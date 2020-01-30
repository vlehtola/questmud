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
        set_dex(query_dex()*3);
        set_con(query_con()*2);
        set_max_hp(query_hp()+(10000));
        set_al(-3);
        set_gender(1);
        set_short("Drazil's bodyguard is standing here");
        set_long("Strong looking man is securing the area.\n"
                 "He is a well trained ranger and he knows how to use\n"+
                 "his hands and feet.\n");
        set_block_dir("up");
set_block_dir("down");
        set_skill("kick", 100);
        set_skill_chance("kick", 80);
        set_skill("tumble", 20);
        set_skill("stun", 80);
        set_skill("punch", 100);
        set_skill("bare hands", 100);
        set_skill("attack", 100);
        set_log();

}
