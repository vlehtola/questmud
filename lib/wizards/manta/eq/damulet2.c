inherit "obj/armour";
inherit "obj/armour";
 
reset(arg) {
        ::reset(arg);
        set_name("amulet of K'zing");
        set_alias("amulet");
        set_short("Amulet of K'zing");
        set_long("Amulet of K'zing is made of fine mithril plate attached\n" +
                   "to small pin that connects it to clothing.\n");
        set_ac(2);
        set_weight(1);
        set_value(10000);
        set_slot("amulet");
        set_resists(6, 1);
        set_stats("int", 15);
        set_stats("wis", 15);
        set_stats("spr", 30);
 
}
 
 
 
