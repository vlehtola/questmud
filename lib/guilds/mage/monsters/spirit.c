inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(7);
    set_name("spirit");
    set_hp(100);
    set_max_hp(100);
    set_short("A non-corpseal spirit");
    set_long("This spirit is all transparent and you even have some difficulties to see it.\n");
    set_al(0);
    set_spell_chance(20, "exs fla grs");
    set_resists(100,0);
    set_resists(0,1);
    set_resists(0,2);
    set_resists(0,3);
    set_resists(0,4);
    set_resists(0,5);
    
    set_aggressive(1);
    set_block_dir("forward");
    set_skill("cast essence", 50);
    set_skill("cast fire", 50);
    set_skill("cast grasp", 50);

    set_dead_ob(this_object());
}

monster_died() {
    this_object()->query_attack()->set_quest("magetest");
    return 0;
}

