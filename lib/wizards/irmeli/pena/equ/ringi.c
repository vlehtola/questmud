inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("ring of angels");
    set_alias("ring");
    set_short("A Crystal ring of angels");
    set_long("This Crystal ring of angels is sizzling with yellow light.\n");
    set_ac(1);
    set_value(100000);
    set_weight(2);
    set_stats("str", 2);
    set_stats("con", 1);
    set_stats("hpr", 3);
    set_slot("finger");
}
