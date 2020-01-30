inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("cloak");
    set_short("A light green cloak");
    set_long("This cloak is completely green, but it has some strange marks on it.\n");
    set_ac(10);
    set_slot("cloak");
    set_value(2000);
    set_weight(1);
    set_stats("spr", 5);
    set_resists(3,20);
}
