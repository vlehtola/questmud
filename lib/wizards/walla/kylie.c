

inherit "obj/monster"; 
 
reset(arg) {
    ::reset(arg);
    set_level(25);
    set_name("janina");
    set_short("Kylie Minogue, Wallas hjani");
    set_exp(2147483647);
    set_long("This is a typical armour.\n");
    set_al(0);
    set_aggressive(0);
    set_dead_ob(this_object());
}
