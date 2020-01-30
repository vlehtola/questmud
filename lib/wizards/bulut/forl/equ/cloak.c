inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_slot("cloak");
    set_name("green cloak");
    set_alias("cloak");
    set_short("A green cloak");
    set_long("This is a well made green cloak.\n");
    set_value(60);
    set_weight(100);
    set_stats("str",1);
}
