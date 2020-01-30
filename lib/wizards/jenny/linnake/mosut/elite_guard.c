inherit "obj/monster";
reset(arg) {
        object money;
        ::reset(arg);
        if(arg) {return; }
        set_name("guard");
        set_race("human");
        set_level(57);
        set_experience(8353432);
        set_str(query_str()*2);
        set_dex(query_dex()*4);
        set_con(query_con()*2);
        set_max_hp(query_hp()+(25000));
        set_al(-3);
        set_gender(1);
        set_short("Captain's elite guard is standing here");
        set_long("Strong looking man whos job is to watch that nobody tries to\n"
                 "enter captain's room. He is not using any weapons, but he surely\n"+
                 "looks like he could kick your ass pretty easily.\n");
        set_block_dir("west");
        set_skill("kick", 100);
        set_skill_chance("kick", 40);
        set_skill("tumble", 20);
        set_skill("stun", 80);
        set_skill("punch", 100);
        set_skill("bare hands", 100);
        set_skill("attack", 100);
        set_log();

}
