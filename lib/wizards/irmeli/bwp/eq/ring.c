inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_slot("finger");
    set_name("ring");
    set_short("Well crafted ruby ring");
    set_long("A ruby ring is inlaid with ivory and sharp fragments of crystal.\n"+
             "A copper engraving has been carved inside the ring. The ring\n"+
             "is crafted so well that it fits everybody's finger");
    set_value(2000);
    set_weight(100);
    set_stats("dex", 3);
    set_stats("str", 3);
    set_stats("con", 3);
}
