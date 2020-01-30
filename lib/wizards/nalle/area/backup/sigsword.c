inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("sword");
    set_short("Sword of the Black Rose");
    set_long("A long black sword, cold to the touch.\n");
    set_material(8);
    set_class(47);
    set_weapon_type("blade");
    set_value(2100);
    set_weight(3);
    set_stats(2,3);
}
