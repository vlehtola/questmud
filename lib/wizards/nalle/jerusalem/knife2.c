inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("knife");
    set_short("A small knife");
    set_long("A small, easily concealable knife.\n");
    set_wc(16);
    set_weapon_type("dagger");
    set_value(12);
    set_weight(30);
}

