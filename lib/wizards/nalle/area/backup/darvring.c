inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("Ring");
    set_alias("ring");
    set_short("An ebon ring");
    set_long("It is a small, black ring made out of ebony. There\n" +
                    "are small emeralds and rubies embedded in it.\n");
    set_ac(1);
    set_value(11000);
    set_weight(1);
    set_stats("wis", 2);
    set_stats("int", 2);
    set_stats("spr", 2);
    set_slot("finger");
}
