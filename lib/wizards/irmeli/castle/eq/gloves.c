inherit "obj/armour";

start() {
set_class(1);
    set_slot("hands");
    set_name("gloves");
    set_short("Dark gloves of the Master Knight");
    set_long("The gloves are black. Made of leather. Two white strings, which tighten\n"+
             "the gloves to the wearer's arms, are attached to the gloves. Knuckle heads\n"+
             "of the gloves are reinforced with mithril");
    set_stats("con", 20);
    set_stats("str", -2);
    set_stats("dex", 8);
    set_value(3000);
    set_weight(200);
}


