inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("maul");
    set_short("Bronze maul");
    set_long("A bronze maul.\n");
    set_material(5);
    set_class(55);
    set_weapon_type("bludgeon");
    set_value(5500);
    set_weight(3);
    set_stats(3,2);
}
