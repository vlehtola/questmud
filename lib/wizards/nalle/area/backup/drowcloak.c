inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("cloak");
    set_alias("armour");
    set_short("A dark cloak");
    set_long("A long dark cloak with incomprehensible symbols on it.\n");
    set_ac(20);
    set_value(2100);
    set_weight(3);
    set_stats("int", 5);
    set_stats("spr", 4);
    set_slot("cloak");
}
