inherit "obj/armour";

drop() { return 1; }

start() {
        set_class(1);
        set_slot("special");
        set_name("belt");
        set_short("The broad belt of Deleria's Warlord");
        set_long("The belt belongs to the best warrior of Deleria.\n"+
                 "It has ancient runes on it which tell of heroic acts\n"+
		 "done and forgotten long time ago. The belt seems\n"+
		 "to have a divine origin");

        set_weight(300);
        set_value(0);
        set_stats("str", 15);
        set_stats("con", 20);
        set_resists("cold", 25);
        set_resists("fire", 25);
        set_resists("electric", 25);
}

query_no_save() { return 1; }
