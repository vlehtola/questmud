inherit "obj/monster";
 
reset(arg) {
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(30);
    set_name("Skeleton");
    set_alias("skeleton");
    set_short("Warrior skeleton.");
    set_long("This is skeleton of a dead warrior.\n");
    set_al(-60);
    set_undead(1);
    set_skill_chance("strike", 100);
    set_aggressive(0);
    set_move_at_random(2);
    set_skill("agility", 100);

    weapon = clone_object("/wizards/grathlek/area2/eq/sword.c");
    move_object(weapon, this_object());
    init_command("wield sword");
}
