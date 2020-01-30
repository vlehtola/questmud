inherit "obj/monster";
 
reset(arg) {
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(30);
    set_name("paladin");
    set_alias("guard");
    set_short("Paladin guard of the Eternal light");
    set_long("Your presence doesn't seem to distrupt him. He\n"+
             "looks like very strong and big.\n");
    set_al(100);
    set_race("human");
    set_block_dir("enter"); 

    weapon = clone_object("/wizards/grathlek/area1/eq/sword.c");
    move_object(weapon, this_object());
    init_command("wield blade"); 
}
