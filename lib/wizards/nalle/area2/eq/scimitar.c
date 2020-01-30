inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("scimitar");
    set_short("A sharp scimitar");
    set_long("A sharp scimitar, commonly used by bandits and outlaws.\n");
    set_weapon_type("blade");
    set_value(210);
    set_weight(90);
}
