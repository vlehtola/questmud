inherit "obj/armour";

drop() { return 1; }

start() {
        set_class(1);
        set_slot("special");
        set_name("necklace");
        set_short("The shining necklace of Realm's Guardian");
        set_long("This necklace has been made for the guardian of this realm.\n"+
                 "Light beams of thousands of different colours emit from it,\n"+
		 "the glow is soft and somehow comforting");
        set_weight(50);
        set_value(0);
        set_stats("int", 15);
        set_stats("con", 12);
        set_stats("spr", 16);
        set_resists("cold", 25);
        set_resists("fire", 25);
        set_resists("electric", 25);
}

query_no_save() { return 1; }

