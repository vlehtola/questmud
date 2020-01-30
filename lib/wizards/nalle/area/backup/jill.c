inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(26);
    set_name("Jill");
    set_alias("jill");
    set_short("Jill of the Jungle");
    set_long("Jill seems convinced she can save her husband from the evil Dequan knights.\n");
    set_al(0);
    set_spell_chance(50, "exs fla grs");
    set_aggressive(1);
    set_block_dir("down");
    set_skill("cast essence", 50);
    set_skill("cast fire", 50);
    set_skill("cast grasp", 50);
    set_skill("mana control", 10);
    set_skill("chanting", 10);
    set_dead_ob(this_object());
}

monster_died() {
    this_object()->query_attack()->set_quest("Jill",6);
    tell_object(this_object()->query_attack(), "You complete the quest of slaying Jill of the Jungle.\n");
    return 0;
}
