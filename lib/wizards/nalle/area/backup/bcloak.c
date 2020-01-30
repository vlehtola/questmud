inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("Cloak");
    set_alias("cloak");
    set_short("The Eclipse Cloak");
    set_long("An extremely beautiful cloak, that seems to conceal its bearer\n" +
	     "almost completely.\n");
    set_ac(40);
    set_value(70000);
    set_weight(4);
    set_stats("dex", 10);
    set_stats("hpr", 3);
    set_slot("cloak");
}
