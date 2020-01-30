inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("helm");
    set_short("An iron helm");
    set_long("Well made iron helm reinforced with steel covers well\n"+
		"one's head. It emits some wierd black glowing aura.\n");
    set_ac(50);
    set_value(5000);
    set_weight(500);
    set_slot("head");
    set_stats("str", 3);
    set_stats("con", 5);
    set_stats("hpr", 5);
}
