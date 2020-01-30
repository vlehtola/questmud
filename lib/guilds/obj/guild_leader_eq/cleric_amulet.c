inherit "obj/armour";

drop() { return 1; }

start() {
        set_class(1);
        set_slot("special");
        set_name("amulet");
        set_short("The golden amulet of Cyral's Highpriest");
        set_long("The amulet has been made of pure gold. A golden chain has\n"+
		 "been attached to it. The amulet's age cannot be guessed,\n"+
		 "it must be old but still it shines as it was brand new\n"+
		 "Cyral's divine precense feels very close");
        set_weight(500);
        set_value(0);
        set_stats("int", 15);
        set_stats("con", 12);
        set_stats("spr", 16);
        set_resists("cold", 25);
        set_resists("fire", 25);
        set_resists("electric", 25);
}

query_no_save() { return 1; }
