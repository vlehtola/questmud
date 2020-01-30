inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("short sword");
    set_alias("sword");
    set_short("A short sword");
    set_long("This is a typical iron short sword, that Duranghoms smithes produce.\n");
    set_wc(40);
    set_weapon_type("blade");
    set_value(800);
    set_weight(2);
}
