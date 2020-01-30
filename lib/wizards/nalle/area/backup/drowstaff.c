inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("staff");
    set_short("Staff of Comprehension");
    set_long("A well made staff with magical powers.\n");
    set_material(3);
    set_class(10);
    set_weapon_type("bludgeon");
    set_value(2100);
    set_weight(1);
    set_stats(5,6);
}
