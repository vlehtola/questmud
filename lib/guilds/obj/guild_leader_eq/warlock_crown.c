inherit "obj/armour";

drop() { return 1; }

start() {
        set_class(1);
        set_slot("special");
        set_name("crown");
        set_short("The Crown of the Heretic");
        set_long("This crown symbolizes the power of the Warlock leader.\n"+
                 "It is made of iron and it has long sharp spikes pointing\n"+
                 "to all directions. It is very cruel-looking but that is\n"+
                 "only suitable for Warlocks");
        set_weight(400);
        set_value(0);
        set_stats("str", 10);
        set_stats("int", 8);
        set_stats("con", 15);
        set_stats("spr", 10);
        set_resists("cold", 25);
        set_resists("fire", 25);
        set_resists("electric", 25);
}

query_no_save() { return 1; }
