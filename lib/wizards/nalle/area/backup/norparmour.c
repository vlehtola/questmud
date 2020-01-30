inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("armour");
    set_alias("old armour");
    set_short("Norp Alemouth's old armour");
    set_long("This is Norp Alemouth's old armour.\n");
    set_ac(30);
    set_value(4000);
    set_weight(10);
    set_stats("str", -1);
    set_stats("hpr", 5);
    set_slot("torso");
}

