inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("armour");
    set_alias("battlearmour");
    set_short("A Dequan battlearmour");
    set_long("The Dequan battlearmour would cover your torso.\n");
    set_ac(45);
    set_value(9000);
    set_weight(10);
    set_stats("str", 3);
    set_stats("hpr", 4);
    set_slot("torso");
}
