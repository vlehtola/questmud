inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(40);
    set_name("spirit");
    set_short("A strong non-corpseal spirit");
    set_long("This spirit is all transparent and you even have some difficulties to see it.\n");
    set_al(0);
    set_spell_chance(100, "exs fla blt");
    set_resists(100,0);
    set_resists(50,1);
    set_resists(50,2);
    set_resists(50,3);
    set_resists(50,4);
    set_resists(50,5);
    
    set_aggressive(1);
    set_block_dir("out");
    set_skill("cast essence", 100);
    set_skill("cast fire", 100);
    set_skill("cast bolt", 100);
    set_skill("mastery of fire", 100);
    set_skill("chanting", 100);
    set_skill("mana control", 100);

    set_dead_ob(this_object());
}

