inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,longsword;
    ::reset(arg);
    if(arg) { return; }
    set_name("guard");
    set_level(random(5)+20);
    set_al(5);
    set_alias("human");
    set_race("human");
    set_short("Tall castle guard is guarding the entrance");
    set_long("The guard look pretty young and he is obviously proud about being a \n"+
             "guard in this mighty old castle. He is wielding a longsword and\n"+
              "wearing black plate-mail type  armour.\n");

    set_aggressive(0);
    set_gender(1);
    set_str(query_str()+10);
    set_max_hp(query_hp()+random(500));
    set_hp(query_max_hp());

   set_skills ("critical",40);
   set_skills ("doublehit",30);
/*
   armour = clone_object("/wizards/jenny/linnake/rojut/black_armour");
    move_object(armour, this_object());
    init_command("wear armour");
   longsword = clone_object("/wizards/jenny/linnake/mosut/guard_sword");
    move_object(longsword, this_object());
    init_command("wield sword");
    */
    if (!chat_str) {
                                chat_str = allocate(4);
                                chat_str[0] = "Guard booms: 'Hello there friend!'\n";
                                chat_str[1] = "guard whistles something.\n";
                                chat_str[2] = "Guard booms: 'Did you come here to see our king?'\n";
                                          chat_str[3] = "Guard asks: 'Is there anything I can do for you?'\n";
                         }
                         load_chat(4, chat_str);
}





