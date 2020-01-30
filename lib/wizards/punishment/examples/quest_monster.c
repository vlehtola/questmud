inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    set_level(10);
    set_name("spirit");
    set_short("A non-corpseal spirit");
    set_long("This spirit is all transparent and you even have some difficulties to see it.\n");
    set_al(0);
    set_spell_chance(50, "exs fla grs");
    set_aggressive(1);
    set_block_dir("out");
    set_skill("cast essence", 50);
    set_skill("cast fire", 50);
    set_skill("cast grasp", 50);
    set_skill("mana control", 20);
    set_skill("chanting", 40);
    set_dead_ob(this_object());
}

monster_died() {
    this_object()->query_attack()->set_quest("[quest_name]");
    tell_object(this_object()->query_attack(), "As you destroy the spirit, you have completed the [quest_name].\n");
    return 0;
}
