inherit "obj/monster";
status q;
reset(arg) {
    string chat_str, a_chat_str;
    object money,weapon,armour;
    ::reset(arg);
    if (arg) { return; }
    set_level(50);
    set_gender(1);
    set_race("human");
    set_name("gerald");
    set_alias("Gerald");
    set_short("Gerald the wine maker");
    set_long("This man is the one who makes the wine, without him there\n" +
             "wouldn't be any wine in this place. Gerald was once a great\n" +
             "warrior but as many others he has fallen in to the world of\n" +
             "alcohol.\n");
    set_al(0);
    set_log();
    set_aggressive(0);
    set_move_at_random(0);
 if(!q) {
        chat_str = allocate(3);
        chat_str[0] = "Gerald mumbles 'where did i put that bottle.\n";
        chat_str[1] = "Gerald says 'im supposed to deliver an old vintage wine bottle soon, but i can't find it.\n";
        chat_str[2] = "Gerald says 'i wish that someone could help me with finding that bottle \n";
load_chat(3, chat_str);
}
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Gerald shouts 'Why did you attack me im just an ordinary wine maker!! \n";
}
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    armour = clone_object("/wizards/ozmala/areat/wine-cellar/eqs/bracers");
    move_object(armour, this_object());
    init_command("wear bracers");

    weapon = clone_object("/wizards/ozmala/areat/wine-cellar/eqs/dagger");
    move_object(weapon, this_object());
    init_command("wield dagger");

}

catch_tell(str) {
        string tmp1, tmp2, chat_str;
           object ob;
        ::catch_tell(str);
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("bottle", this_object());
    if (ob && this_player()->query_name() == tmp1) {
    item_ob = present("kekeilevakoshubullo", this_object());
    destruct(item_ob);
    write("Gerald says 'Thank you alot.'\n");
  q = 1;
chat_str = allocate(1);
chat_str[0] = "Gerald says: 'Now i can deliver this darn bottle'\n";
load_chat(3, chat_str);
    this_player()->set_quest("Seek Gerald's bottle");

  }
 }
}




