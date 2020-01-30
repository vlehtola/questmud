inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_level(25);
    set_name("zombie");
    set_short("A Zombie, risen from the grave");
    set_long("This zombie rules this place.\n");
    set_al(0);
    set_aggressive(1);
    set_undead(1);
    set_block_dir("up");
    set_dead_ob(this_object());
    set_mage(1);
}
