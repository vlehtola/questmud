inherit "obj/armour";
 
reset(arg) {
        ::reset(arg);
        set_name("a emerald ring of k'zing");
        set_alias("ring");
        set_short("A emerald ring of K'zing");
        set_long("This ring if made of mithrild and decorated with emeralds\n" +
                   "The ring is so beatiful that you even might to kill for it.\n");
        set_ac(2);
        set_weight(1);
        set_value(10000);
        set_slot("finger");
        set_resists(5, 1);
        set_stats("int", 10);
        set_stats("wis", 5);
        set_stats("dex", -10);
        set_stats("str", -5);
        set_stats("spr", 20);
        
}
 
