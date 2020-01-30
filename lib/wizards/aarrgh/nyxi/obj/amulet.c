inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("amulet");
    set_alias("amulet");
    set_short("The amulet of disorder");
    set_long("This is the amulet of disorder. The amulet itself has been made of some unknown\n"
             "metal and it is decorated with black onyx stones. The amulet is forged into a shape\n"
             "of pentagram");
    set_ac(5);
    set_value(5000);
    set_stats("int", 4);
    set_stats("wis", 4);
    set_stats("str", -10);
    set_stats("spr", 15);
    set_slot("amulet");

}
