inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("Cape");
    set_alias("cape");
    set_short("A black cape");
    set_long("An extremely beautiful cloak, that seems to conceal its bearer\n" +
             "almost completely.\n");
    set_ac(52);
    set_value(700);
    set_weight(60);
    set_stats("dex", 1);
    set_stats("hpr", 1);
    set_slot("cloak");
}
