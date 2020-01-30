inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("staff");
    set_long("A short and fairly light staff, often used by magic users.\n");
    set_material(1);
    set_class(4);
    set_weapon_type("bludgeon");
    set_value(121);
    set_weight(3);
}

