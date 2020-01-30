inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    set_level(17);
    set_name("guard");
    set_short("A guard dressed in red and white clothes");
    set_long("The guard is standing by the gate and blocking your way to the tower.\n");
    set_al(0);        
    set_aggressive(0);
    set_gender(1);
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "Guard says: 'Only mages are allowed to enter.'\n";
        chat_str[1] =
          "Guard says: 'If you are not a mage, better turn back.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Guard grunts: 'Even if you made your way in, the mages will kill you.'\n";
    }
    load_chat(7, chat_str);
    load_a_chat(10, a_chat_str);
        

    weapon = clone_object("wizards/onarion/tower/eq/halberd.c");
    move_object(weapon, this_object());
}

catch_tell(str) {
    string tmp1;
    object ob;
    if (sscanf(str, "%s is in vigorous combat with Guard.", tmp1)
		&& !attacker_ob) {
         ob = present(tmp1);
         if (ob && living(ob)) { attack_object(ob); }
    }
    ::catch_tell(str);
}

init() {
    ::init();
    if(this_player()->query_guild_level(call_other("world/guilds/guildfun.c",
		"get_guild_number", "Apprentice Mage")) &&
	!this_player()->query_quest("mage_test_failed")) {
	return 1;
    }
    add_action("enter","enter");
}

enter() {
    if (this_player()->query_quests("mage_test_failed")) {
	write("Guard blocks your way and grunts: 'Be gone, you are not wanted here'.\n");
	return 1;
    }
    write("Guard blocks your way and grunts: 'Only mages are allowed to enter.\n");
    return 1;
}




