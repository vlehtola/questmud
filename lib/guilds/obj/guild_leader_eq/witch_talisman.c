inherit "obj/armour";
drop() { return 1; }
start() {
        set_class(1);
        set_slot("special");
        set_name("talisman");
        set_short("Talisman of supreme witchcraft");
        set_long("The talisman of supreme witchcraft. The talisman is made of small golden\n"+
        "rings. A large picture of moon is frontside of the talisman, gleaming strongly");
        set_weight(200);
        set_value(0);
        set_stats("int", 16);
        set_stats("con", 15);
        set_stats("spr", 20);
        set_resists("cold", 25);
        set_resists("fire", 25);
        set_resists("electric", 25);
    }

query_no_save() { return 1; }
