inherit "obj/weapon";
 
reset(arg) {
    ::reset(arg);
    set_name("club");
    set_short("Child's toy club");
    set_long("This is a child's toy club.\n");
    set_material(6);
    set_wc(69);
    set_weapon_type("bludgeon");
    set_value(1);
    set_weight(5);
}
