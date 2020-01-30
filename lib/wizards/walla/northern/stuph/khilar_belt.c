inherit "obj/armour";
 
start() {
set_class(7);
  set_slot("belt");
    set_name("belt");
    set_alias("girdle");
    set_short("The girdle of Storm Giant Strength");
    set_long("An enormously thick belt with a HUGE buckle on the front.\n"+
             "On the buckle is the symbol of a bull's head, and it's made\n"+
             "out of gold. The belt itself is probably made of the bull's\n"+
             "skin.");
    set_value(50);
    set_weight(10);
    set_stats("str", 10);
    set_stats("con", 5);
    set_resists("fire", 10);
    set_stats("dex", -4);
}

