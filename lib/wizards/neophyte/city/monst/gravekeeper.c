inherit "obj/monster";
object armour,armour1,key;
status q;
reset(arg) {
        string chat_str;
        ::reset(arg);
        if(arg) {return; }
        set_name("keeper");
        set_level(100);
        set_gender(1);
        set_al(10);
        set_race("human");
        set_short("Graveyard keeper");
        set_long("The keeper is quite old man and years haven't treaten him well.\n"+
                 "He looks quite thin and fragile. He is wearing a dark cape and scythe\n"+
                 "in his hands. The keeper is constantly looking for undeads and sending\n"+
                 "them back to the other side if he meets them.\n");
                             if (!chat_str) {
                                         chat_str = allocate(3);
                                         chat_str[0] =
                                 "Keeper looks at the bone door.\n";
                                 chat_str[1] =
                                 "Keeper says: 'I am the graveyard keeper.'\n";
                                 chat_str[2] = "Keeper says: 'I need something warm to wear.\n";
                                }
        set_skill("tumble", 100);
        load_chat(3, chat_str);
        armour = clone_object("/wizards/neophyte/city/eq/armour");
        move_object(armour, this_object());
        armour1 = clone_object("/wizards/neophyte/city/eq/armour1");
    move_object(armour1, this_object());
    key = clone_object("/wizards/neophyte/city/obj/gravekey");
    move_object(key, this_object());
    init_command("wear all");
    set_max_hp(query_hp()*5);
    set_hp(query_max_hp());
}

ask_question(str) {
	object ob,kit;
	ob = present("lammas_cloak", this_player());
        if(str == "door") {
                say("Keeper says: 'The rule is that the gates are closed during nights!'\n");
                return 1;
        }
        if(str == "graveyard") {
                        say("Keeper says: 'This graveyard is the final resting place of sailors.\n");
                        return 1;
                }
                if(str == "warm" || str == "wear") {
					say("Keeper says: 'I might have task for you.'\n");
					return 1;
				}
                if(str == "task") {
					say("Keeper says: 'I need something warm to wear.\n");
					say("Keeper says: 'Go get a sheepskin cloak, i have heard that the armourer can make one.\n");
					say("Keeper says: 'When you have finished to remember to ask me about present.\n");
					return 1;
				}

                if(str == "sailors") {
                        say("Keeper says: 'Yes they are buried in the graveyard.\n");
                        return 1;
                }
                if(str == "open" || str == "open door" || str == "open bone door") {
                        say("Keeper says: 'Just a second and i will gey my key.\n");
                        say("Keeper takes key from his pocket.\n");
                        init_command("unlock door with key");
                        init_command("open door");
                        say("Keeper says: 'There you go.'\n");
                        return 1;
                }
                if(str == "present") {
					if(!ob) {
						say("Keeper says: 'But you don't have the right cloak.\n");
						return 1;
					}
					if(q) { say("Keeper says: 'I dont need anymore that.\n");
					return 1; }
					say("Keeper says: 'Ah now i can be awake during cold night.\n");
					destruct(ob);
					kit = clone_object("/wizards/neophyte/city/obj/tinningkit");
					move_object(kit,this_player());
					say("Keeper says: 'Here is little present for you.\n");
					write("Keeper gives you something.\n");
					q = 1;
					return 1;
				}

        write("Keeper says: 'I dont know anything about that'.\n");
        return 1;

}

catch_tell(str) {
   string tmp1,tmp2;
   int i;
   i = call_other("/obj/timer","query_time_of_day",0);
   ::catch_tell(str);
   if (sscanf(str, "%s knocks the door.", tmp1) == 1) {
        if(i == 1 || i == 2 || i == 5) {
        tell_room("/wizards/neophyte/city/navigator1", "Someone says: 'Wait a second and i will open the door.'\n");
      init_command("unlock door with key");
      init_command("open door");
    return 1;
  }
        tell_room("/wizards/neophyte/city/navigator1", "Someone says: 'I can't open the door at this time of day.'\n");
      return 1;

 }
 if (sscanf(str, "%s arrives from the %s.", tmp1, tmp2) == 2) {
         init_command("close door");
         init_command("lock door with key");
         return 1;
 }
 if (sscanf(str, "%s leaves %s.", tmp1, tmp2) == 2) {
	 init_command("close door");
	 init_command("lock door with key");
	 return 1;
 }
}
