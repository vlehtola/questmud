inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("staff");
    set_long("A magical weapon of great powers.\n");
    set_weapon_type("bludgeon");
    set_value(21000);
    set_weight(800);
    set_wc(60);
    set_stats(3,6);
}
