inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("broom");
    set_short("An old broom");
    set_long("A dusty old broom\n");
    set_material(1);
    set_class(20);
    set_weapon_type("bludgeon");
    set_value(21);
    set_weight(3);
}
