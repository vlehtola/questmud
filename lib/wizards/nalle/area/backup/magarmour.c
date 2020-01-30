inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("armour");
    set_alias("cloak");
    set_short("A red cloak");
    set_long("A well made red cloak with arcane writings on it.\n");
    set_ac(20);
    set_value(700);
    set_weight(5);
    set_stats("int", +1);
    set_stats("spr", 2);
    set_slot("cloak");
}

