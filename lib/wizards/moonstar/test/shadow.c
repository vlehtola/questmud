
inherit "obj/monster";
reset(arg) {
        object money;
        object weapon;
::reset(arg);
        if(arg) {return; }
        set_name("shadow");
        set_race("animal");
        set_level(57);
        set_experience(8353432);
        set_str(query_str()*2);
        set_dex(query_dex()*4);
        set_con(query_con()*2);
        set_max_hp(query_hp()+(25000));
        set_al(-30);
        set_gender(1);
        set_short("Dark shadow floats here");
        set_long("Strong looking shadow is floating here and securing the ladders.\n"
                 "He is totally black and has small gleaming yellow eyes which\n"+
                 "are staring you.\n");
        set_block_dir("up");
        set_skill("tremendous blow", 100);
        set_skill_chance("tremendous blow", 80);
        set_skill("tumble", 40);
        set_skill("stun", 100);
        set_skill("punch", 100);
        set_skill("bare hands", 100);
        set_skill("attack", 100);
        set_log();

    weapon = clone_object("/wizards/moonstar/areas/wasteland/eq/lsword.c");
    move_object(weapon, this_object());
    init_command("wield sword");

}
