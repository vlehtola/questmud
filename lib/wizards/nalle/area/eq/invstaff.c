inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("staff");
    set_long("A simple staff, often used by magic users.\n");
    set_material(4);
    set_class(3);
    set_weapon_type("bludgeon");
    set_value(212);
    set_weight(400);
}
