inherit "obj/monster";
 
reset(arg) {
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(24);
    set_name("paladin");
    set_short("Paladin warrior protecting the temple");
    set_long("Your presence doesn't seem to distrupt him. He\n"+
             "looks like a skilled warrior and is ready for fights.\n");
    set_al(100);
    set_race("human");
    set_skill_chance("kick", 33);
    weapon = clone_object("/wizards/grathlek/area1/eq/spear.c");
    move_object(weapon, this_object());
    init_command("wield sword"); 
}
