inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("sword");
    set_short("Light silvery blade");
    set_long("This is the usual blade used by guards of Strahd.\n");
    set_material(5);
    set_class(10);
    set_weapon_type("blade");
    set_value(210);
    set_weight(1);
}

