inherit "obj/monster"; 
 
reset(arg) {
    ::reset(arg);
    set_level(25);
    set_name("pi");
    set_short("Pi");
    set_exp(314159265);
    set_long("This is a typical armour.\n");
    set_al(0);
    set_aggressive(0);
    set_dead_ob(this_object());
}
