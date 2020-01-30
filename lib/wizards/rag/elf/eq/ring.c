inherit "obj/armour";

start() {
    set_slot("finger");
    set_name("ring");
    set_short("Thick golden ring");
    set_long("This ring has beautiful decorations all over it.\n"+
                "It is made of the finest gold and it is very thick\n"+
                "so it is quite heavy for a ring. It is glowing faintly");
    set_weight(5);
    set_value(1000);
    set_stats("int",2);
    set_stats("wis",2);
    set_stats("str",-5);
    set_stats("con",-5);
    set_stats("spr",5);
}
