inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("knife");
    set_short("A tyrannous knife");
    set_long("A huge knife. It seems like blood flies when you swing it even if you don't hit anything.\n");
    set_material(8);
    set_class(45);
    set_weapon_type("dagger");
    set_value(2100);
    set_weight(2);
    set_stats(1,2);
}
