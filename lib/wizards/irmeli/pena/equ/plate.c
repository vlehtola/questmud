inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("plate of emperor");
    set_alias("plate");
    set_short("A royal plate of emperor");
    set_long("This royal plate of emperor is shining like new. You can only image how much it costs.\n");
    set_ac(55);
    set_value(70000);
    set_weight(800);
    set_stats("str", 10);
    set_stats("con", 7);
    set_stats("hpr", 10);
    set_slot("torso");
}
