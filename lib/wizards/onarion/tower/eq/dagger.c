inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("dagger");
    set_short("A steel dagger");
    set_long("This steel dagger looks well made.\n");
    set_class(30);
    set_value(500);
    set_weight(1);
    set_weapon_type("dagger");
}
