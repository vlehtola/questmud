inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("staff");
    set_long("This is Norp's staff, he uses it to drive away drunkards.\n");
    set_material(6);
    set_class(3);
    set_weapon_type("bludgeon");
    set_value(212);
    set_weight(4);
}

