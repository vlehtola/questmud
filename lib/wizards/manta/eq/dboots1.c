inherit "obj/armour";

reset(arg) {
        ::reset(arg);
        set_name("fire boots");
        set_alias("boots");
        set_short("A fire boots");
        set_long("these boots are made of thick leather.\n");
        set_ac(4);
        set_weight(3);
        set_value(1400);
        set_slot("feet");
        set_resists(3, 1);
        set_stats("con", 5);
        set_stats("dex", 5);
        set_stats("str", -3);
        
}

