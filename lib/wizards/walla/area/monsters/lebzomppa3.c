inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
 
    set_level(27);
    set_name("zombie");
    set_short("A rotting zombie");
    set_long("This zombie rules this place.");
    set_al(0);
    set_block_dir("north");
    set_dead_ob(this_object());
}


