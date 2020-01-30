inherit "obj/armour";

drop() { return 1; }

start() {
        set_class(1);
        set_slot("special");
        set_name("ring");
        set_short("The dragon ring of hwarang clan.");
        set_long("This is the legendary ring of Rhee Ki Haa who was the\n"+
 "leader of legendary group called hwarang. Ring has huge emerald\n"+
 "on it and it is shining brightly.\n");

        set_weight(300);
        set_value(0);
        set_stats("con", 8);
        set_stats("str", 13);
        set_stats("dex", 20);
        set_resists("cold", 25);
        set_resists("fire", 25);
        set_resists("electric", 25);
}

query_no_save() { return 1; }

