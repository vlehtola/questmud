inherit "obj/armour";

reset(arg) {
        ::reset(arg);
        set_name("fire gloves");
        set_alias("gloves");
        set_short("A fire gloves");
        set_long("these gloves are made of thick leather.\n");
        set_ac(4);
        set_weight(2);
        set_value(1400);
        set_slot("hands");
        set_resists(4, 1);
        set_stats("con", 5);
        set_stats("dex", 3);
        set_stats("str", 3);
        set_stats("wis", -5);
        set_stats("int", -5);
        set_stats("hpr", 5);
        
}

