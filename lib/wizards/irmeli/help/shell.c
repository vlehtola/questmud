inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("ant shell");
    set_alias("shell");
    set_short("A thick ant shell");
    set_long("This thick ant shell would cover your torso.\n");
    set_ac(40);
    set_value(10000);
    set_weight(1500);
    set_stats("str", 6);
    set_stats("hpr", 3);
    set_slot("torso");
}
