inherit "obj/armour";

start() {
set_class(1);
set_slot("belt");
    set_name("belt");
    set_short("An ancient belt with a silver buckle");
    set_long("An old belt with a shining silver buckle. A waterfall is engraved\n"+
             "in the buckle. The belt is punctured and there are eight holes\n"+
             "in the belt, for the buckle");
    set_stats("con", 6);
    set_stats("dex", 5);
    set_stats("str", 6);
    set_value(4000);
    set_weight(200);
}

