inherit "obj/monster"; 
 
reset(arg) {
    ::reset(arg);
    set_level(0);
    set_name("monster");
    set_short("monster");
    set_exp(- 10000000);
    set_long("muah.\n");
    set_al(0);
    set_aggressive(0);
    set_dead_ob(this_object());
}
