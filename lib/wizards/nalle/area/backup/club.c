inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("club");
    set_long("A crude club.\n");
    set_material(2);
    set_class(15);
    set_weapon_type("bludgeon");
    set_value(120);
    set_weight(5);
}
