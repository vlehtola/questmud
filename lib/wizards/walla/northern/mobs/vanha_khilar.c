inherit "obj/monster";
 
reset(arg) {
    int i,q;
    string chat_str, a_chat_str;
    object weapon,belt,arms,cloak;
    ::reset(arg);
    if(arg) { return; }
 
    set_race("dwarf");
    set_level(77+random(12));
    set_name("khilarbhunaz");
    set_alias("thane");
    set_short("Khilarbhunaz, the dwarven Thane ");
    set_long("Leb Kamar is a huge man, one of the most imposing persons you've ever seen.\n" +
             "He is armoured from head to toe, and his arsenal of weapons is not to be taken\n" +
             "lightly. It seems that nothing could penetrate his defences. His goal is clear,\n" +
             "to kill all invading forces.\n");
    set_al(-35);
    set_max_hp(30000);
    set_hp(query_max_hp());
    set_gender(1);
    set_log();
 
 
    weapon = clone_object("/wizards/walla/northern/stuph/khilar_axe");
    move_object(weapon,this_object());
    init_command("wield axe");
   
    belt = clone_object("/wizards/walla/northern/stuph/khilar_belt");
    move_object(belt,this_object());
    init_command("wear belt");
 
    arms = clone_object("/wizards/walla/northern/stuph/khilar_arms");
    move_object(arms,this_object());
    init_command("wear bracelets");
 
    cloak = clone_object("/wizards/walla/northern/stuph/khilar_cloak");
    move_object(cloak,this_object());
    init_command("wear cloak");
 
    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Khilarbhunaz says: 'If you want to fight me, we'll do it the old fashioned way'.\n";
        chat_str[1] =
          "Khilarbhunaz says: 'You and me boy. Mano a mano.'.\n";
        chat_str[2] =
          "Khilarbhunaz says: 'Let's fight like fighters should'\n";

   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Khilarbhunaz shouts: 'Hahaa. Now you die!'.\n";
    }
       load_chat(3, chat_str);
       load_a_chat(3, a_chat_str);
   
       set_dead_ob(this_object());
}
 
monster_died() {
    tell_object(this_object()->query_attack(),
    "Khilarbhunaz's eyes widen in terror as he realizes that he is dying.\n");
    shout("Joku iivil monsu kuolee ku "+this_player()->query_name()+" irrottaa silta paan!\n");
     return 0;
}

