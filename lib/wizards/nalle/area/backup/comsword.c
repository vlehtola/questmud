inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("sword");
    set_short("Purge, the commander's sword");
    set_long("A sharp red sword. The blade occasionally glows bright red\n");
    set_material(9);
    set_class(50);
    set_weapon_type("blade");
    set_value(30000);
    set_weight(3);
    set_stats(1,2);
}
