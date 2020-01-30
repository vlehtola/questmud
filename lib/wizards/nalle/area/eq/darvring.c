inherit "obj/armour";

start() {
    set_class(3);
    set_name("ring");
    set_short("An ebon ring");
    set_long("It is a small, black ring made out of ebony. There\n" +
                    "are small emeralds and rubies embedded in it.");
    set_stats("wis", 5);
    set_stats("int", 5);
    set_weight(50);
    set_value(3500);
    set_stats("spr", 25);
    set_slot("finger");
}
