inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("keyboard");
    set_short("Deep Blue(tm)'s keyboard");
    set_long("This is a regular 101-key QWERTY IBM keyboard, Deep Blue(tm) has used it for quite a while.\n");
    set_material(10);
    set_class(35);
    set_weapon_type("bludgeon");
    set_value(5000);
    set_weight(5);
}
