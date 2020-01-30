inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("robes");
    set_alias("cloak");
    set_short("Shining white robes");
    set_long("These white robes are the brightest white you have ever seen.\n");
    set_ac(21);
    set_value(1000);
    set_weight(3);
    set_stats("wis", 5);
    set_stats("spr", 5);
    set_slot("cloak");
}
