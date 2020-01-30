inherit "obj/armour";

drop() { return 1; }

start() {
        set_class(1);
        set_slot("special");
        set_name("pendant");
        set_short("The dark pendant of necromancy");
        set_long("This pendant is made from the skins of victims that necromancers\n"+
                 "have slayed. On the pendant is dryed dark blood. The pendant is\n"+
                 "attached in to small bones that have been tied together");
        set_weight(400);
        set_value(0);
        set_stats("int", 15);
        set_stats("con", 12);
        set_stats("spr", 20);
        set_resists("cold", 25);
        set_resists("fire", 25);
        set_resists("electric", 25);
}

query_no_save() { return 1; }
