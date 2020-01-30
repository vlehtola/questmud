inherit "obj/monster";

reset(arg) {
    int i,q;
    string chat_str, a_chat_str;
    object weapon,belt,arms,cloak;
    ::reset(arg);
    if(arg) { return; }
    set_race("dwarf");
    set_str(query_str()*2);
    set_max_hp(query_hp()*3);
    set_dex(query_dex()*2);
    set_level(77+random(12));
    set_name("khilarbhunaz");
    set_alias("thane");
    set_short("Khilarbhunaz, the dwarven Thane ");
    set_long("Khilarbhunaz, the dwarven thane is an old but still strong looking dwarf.\n" +
             "He is watching your movements and he is ready to defend himself if he has to.\n" +
             "In his right hand, he wields the legendary elvenslayer and he is wearing\n" +
             "his old cloak.\n");
    set_al(-35);
    set_gender(1);
    set_experience(19533432);
    set_mage(1);
    set_skill("stun", 100);
    set_skill("attack", 100);
    set_skill("stun", 100);
    set_skill("tremendous blow", 50);
    set_skill_chance("tremendous blow", 50);
    set_skill("cuts", 70);
    set_skill("tumble", 40);
    set_skill("doublehit", 50);
    set_skill("find weakness", 80);
    set_skill("enhance criticals", 50);
    set_skill("dodge", 100);
    set_skill("foresee attack", 100);
    set_skill("parry", 100);
    set_skill("tumble", 10);
    set_skill("counter spell", 80);
    set_skill("reflect spell", 50);
    set_skill("axes", 90);
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
    tell_room(environment(this_object()), "Khilarbhunaz's eyes widen in terror as he realizes that he is dying.\n");
    shout("Khilarbhunaz screams in pain as "+this_player()->query_name()+" rips his head off!\n");
     return 0;
}
