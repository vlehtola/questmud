inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_slot("finger");
    set_name("ring");
    set_short("Silvered ring of 'Angel Falls'");
    set_long("A silvered ring, ringed with two, golden stripes. A symbol of raven\n"+
             "is carved inside the ring. The ring is ice-cold, therefore a small\n"+
             "layer of ice, covers the ring");

    set_value(1000);
    set_weight(100);
    set_stats("dex", 3);
    set_stats("str", 4);
    set_stats("con", 3);
}
