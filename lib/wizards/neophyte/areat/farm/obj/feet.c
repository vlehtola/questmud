inherit "obj/armour";

start() {
        set_class(5);
        set_slot("feet");
        set_name("slippers");
        set_short("White and black coloured slippers");
        set_long("These slippers are made from skin of cows. They are little slippery\n"+
                 "and walking with these arent the best thing to do.\n");
        set_weight(400);
        set_value(500);
        set_stats("dex", -3);
        set_stats("str", -2);
        set_stats("spr", 4);
        set_stats("wis", 3);
}
