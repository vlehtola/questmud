inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_slot("finger");
    set_name("ring");
    set_short("Bone ring of Sanity");
    set_long("The ring is gorged from bone, adorned with jewels. Big jewels have\n"+
             "been inlaid into the ring, forming a circle around the ring.\n"+
             "A tiny, black skull with red eyes is carved into the ring. \n"+
             "The ring is completely circular");

    set_value(3000);
    set_weight(100);
    set_stats("str", 10);
    set_stats("con", 5);
}
