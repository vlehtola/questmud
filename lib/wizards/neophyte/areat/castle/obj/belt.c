inherit "obj/armour";

start() {
        set_class(4);
        set_slot("belt");
        set_name("belt");
        set_short("Brown leather belt");
        set_long("This belt is made of brown animal skin. "+
                 "It is rewarded to captain for helping Pidur "+
                 "to archieve his status");
        set_weight(200);
        set_value(500);
        set_stats("str", 2);
        set_stats("con", 1);
}
