inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    set_level(90);
    set_name("sorian");
    set_alias("mage");
    set_alt_name("master");
    set_short("Sorian the Master Mage");
    set_long("Sorian is the master of the advanced mages guild.\n");
    set_al(50);
    set_al_aggr(300);
    set_aggressive(0);
    set_gender(1);
    if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] =
"Sorian says: 'You should train power concentration, it is the best of the boosting skills'.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(2);
        a_chat_str[0] = "The Master shouts: 'Die BASTARD!'.\n";
        a_chat_str[1] =
"The Master says: 'Soon Sinrad will be here, and you will die by his sword!'\n";
    }

    load_chat(5, chat_str);
    load_a_chat(20, a_chat_str);

    set_mage(1);
}

catch_tell(str) {
  string tmp1,tmp2,tmp3;
  ::catch_tell(str);
  if (sscanf(str, "%s says%srecommendation%s",tmp1,tmp2,tmp3) == 3) {
    if (present("recommendation",this_player())) {
	write("Sorian says 'But you already have one.'\n");
	return 1;
    }
    write("Sorian says 'You want a recommendation from me? Well here you are..'\n");
    write("Sorian hands you a recommendation scroll.\n");
    say("Sorian hands a scroll to "+this_player()->query_name()+".\n",this_player());
    move_object(clone_object("/world/mage/objects/recommendation"), this_player());
    return 1;
  }
}
