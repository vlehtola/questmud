inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("shield");
    set_short("A well polished iron shield");
    set_long("A shield with steel reinforcement.\n");
    set_value(500);
    set_weight(800);
    set_type(7);
    set_shield_factor(8);
}
