inherit "obj/monster";

object enroller;
int in_test;

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    set_level(60);
    set_name("man");
    set_alias("mage");
    set_alt_name("keeper");
    set_short("A man in red robes called the Test Keeper");
    set_long("This man has covered his face with the hood of his robes.\n"+
	"People call him the Test Keeper. Maybe you should listen to him for a while.\n");
    set_al(10);
    set_al_aggr(700);
    set_aggressive(0);
    set_gender(1);
    if (!chat_str) {
        chat_str = allocate(4);
        chat_str[0] =
"The Keeper says: 'To enrol to the test use 'test enrol', read the rules\n"+
"first thou'.\n";
        chat_str[1] =
"The Keeper says: 'Use 'test rules' to see the rules of the Test'.\n";
        chat_str[2] =
"The Keeper says: 'You should have some Naturalist element knowledge "+
"before taking the Test..\n";
        chat_str[3] =
"The Keeper says: 'Physical power will not help you here'.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The keeper hisses: 'You fool!'\n";
    }
    load_chat(30, chat_str);
    load_a_chat(20, a_chat_str);
}

init() {
    ::init();
    add_action("test", "test");
}

test(str) {
    if (str == "rules") {
	write("The Keeper lists you the rules of the test:\n");
	write("  1. To win the Test, you must find a way out.\n");
	write("  2. You must use magic to complete the test.\n");
	write("  3. Failing the Test means dying.\n");
	write("  4. You have to survive on your own.\n");
	write("  5. If you fail the test, you cannot try it again.\n");
	write("  6. Only be completing the Test you may pass the Guardian.\n");
	write("  7. You are not allowed to have any outside help while in the Test.\n");
	write("  8. All protections are removed when you start the test.\n");
	return 1;
    }
    if (str == "enrol") {
    	if (this_player()->query_guild_level(call_other("/world/guilds/guildfun.c",
 		"get_guild_number", "Advanced Mages")) != 10) {
	  write("The Keeper says: 'You have to complete the Advanced Mages"+
		" guild before you can take the test.\n");
	  return 1;
	}
	if (this_player()->query_quests("mage_test_complete")) {
	  write("The Keeper says: 'But you have all ready completed the Test!'\n");
	  return 1;
	}
        if (this_player()->query_quests("mage_test_failed")) {
	  if (!this_player()->query_quests("mage_test_complete")) {
            write("The Keeper says: 'But you have all ready failed the Test!'\n");
            return 1;
	  }
        }
	check_test_in_use();
	if (enroller) {
	  write("The Keeper says: 'Sorry, but the test is all ready in use by "+
		enroller->query_name()+"'.\n");
	  return 1;
	}
	write("The Keeper says: 'So be it. I have to make some preparations. Your test will\n"+
	    "start in 10 minutes. Be here when the time is done.\n");
	enroller = this_player();
	call_out("enrol_sequence", 180, 1);
	return 1;
    }
}

enrol_sequence(arg) {
    if (!enroller) { return; }
    if (arg == 1) {
	tell_object(enroller, "The Keepers voice echoes in your mind: '7 minutes to the Test.'\n");
	call_out("enrol_sequence", 180, 2);
    }
    if (arg == 2) {
	tell_object(enroller, "The Keepers voice echoes in your mind: '4 minutes to the Test.'\n");
	call_out("enrol_sequence", 180, 3);
    }
    if (arg == 3) {
	tell_object(enroller, "The Keepers voice echoes in your mind: 'The Test starts in 1 minute.'\n");
	call_out("enrol_sequence", 40, 4);
    }
    if (arg == 4) {
	tell_object(enroller,
"The Keepers voice echoes in your mind: 'Still few seconds. Prepare thyself.'\n");
	call_out("enrol_sequence", 20, 5);
    }
    if (arg == 5) {
	if (!present(enroller->query_real_name(), environment(this_object()))) {
	  tell_object(enroller, "The Keepers voice echoes in your mind:"+
		" 'You were not here in time. You missed the Test.\n");
	  enroller = 0;
	  return 1;
	}
	tell_object(enroller, "The Keepers voice echoes in your mind: 'Let the Test begin!'\n");
	enroller->remove_minor_prot();
	enroller->remove_lesser_prot();
	enroller->remove_greater_prot();
	tell_object(enroller, "Your vision blurs and suddenly you stand elsewhere.\n");
	move_object(enroller, "/world/mage/mag/test_first");
	enroller->set_quest("mage_test_failed",0,1);
	clone_object("world/mage/mag/ld_preventer")->start(enroller);
	in_test = 1;
	return 1;
    }
}

remove_enroller() {
   enroller = 0;
   in_test = 0;
}


check_test_in_use() {
   int enroller_found;
   object ob;
   if (enroller && in_test) {
     ob = find_object("/world/mage/mag/test_first.c");
     if (ob && present(enroller->query_real_name(), ob)) {
	enroller_found = 1;
     }
     ob = find_object("/world/mage/mag/test_room.c");
     if (ob && present(enroller->query_real_name(), ob)) {
	enroller_found = 1;
     }
     ob = find_object("/world/mage/mag/test_room2.c");
     if (ob && present(enroller->query_real_name(), ob)) {
	enroller_found = 1;
     }
     ob = find_object("/world/mage/mag/test_room3.c");
     if (ob && present(enroller->query_real_name(), ob)) {
	enroller_found = 1;
     }
     if (!enroller_found) {
	remove_enroller();
	return;
     }
     return 1;
   }
}

