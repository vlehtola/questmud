inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("axe");
    set_short("The Blasphemer, a blood dripping axe");
    set_long("A tyrannous axe made of some black metal. It's covered by numerous stains of blood.\n");
    set_material(9);
    set_wc(80);
    set_weapon_type("axe");
    set_value(21000);
    set_weight(6);
    set_stats(1,7);
}
