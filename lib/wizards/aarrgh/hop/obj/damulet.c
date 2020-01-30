inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("Amulet of death");
    set_alias("amulet");
    set_short("Black Amulet of Death");
    set_long("This amulet glows evil black light. It seems to be magical\n");
    set_ac(40);
    set_value(5000);
    set_weight(1);
    set_stats("str", 10);
    set_stats("dex", 15);
    set_stats("hpr", 20);
    set_slot("amulet");
}
