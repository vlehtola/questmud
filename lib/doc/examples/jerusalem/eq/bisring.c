inherit "obj/armour";

start() {
    set_class(1);
    set_name("ring");
    set_short("An ivory ring");
    set_long("A ring made of ivory. It has some cryptic writings on it, and\n" +
                    "you immediately feel very attached to it.\n");
    set_stats("int", 2);
    set_stats("wis", 1);
    set_stats("spr", 3);
    set_weight(150);
    set_value(2400);
    set_slot("finger");
}
