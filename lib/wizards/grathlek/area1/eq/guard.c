inherit "obj/monster";
 
reset(arg) {
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(25);
    set_name("Paladin");
    set_alias("paladin");
    set_short("Paladin Gatekeeper");
    set_long("He stands here and guards the entrance of the Temple.\n");
    set_al(100);
    set_aggressive(0);
    set_block_dir("enter");
    set_skill("defend", 80);
    set_skill("dodge", 60);
    set_skill("parry", 60);

    weapon = clone_object("/wizards/grathlek/area1/eq/spear.c");
    move_object(weapon, this_object());
    init_command("wield spear");
}
