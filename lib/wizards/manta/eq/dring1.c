inherit "obj/armour";
 
reset(arg) {
        ::reset(arg);
        set_name("a diamond ring of k'zing");
        set_alias("ring");
        set_short("A diamond ring of K'zing");
        set_long("This ring if made of mithrild and decorated with diamonds\n" +
                   "It's known this ring gives great powers to it's holder.\n");
        set_ac(4);
        set_weight(1);
        set_value(15000);
        set_slot("finger");
        set_resists(5, 1);
        set_stats("int", 20);
        set_stats("wis", 10);
        set_stats("dex", -20);
        set_stats("str", -10);
        set_stats("spr", 40);
        
}
 
