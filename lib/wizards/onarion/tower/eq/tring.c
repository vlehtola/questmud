inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("ring");
    set_short("The silver ring of the Tutor");
    set_long("This silver ring is full of carvings.\n");
    set_ac(10);
    set_slot("ring");
    set_value(10000);
    set_stats("spr", 10);
    set_stats("int", 5);
    set_stats("wis", 5);
}
