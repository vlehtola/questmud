inherit "obj/armour";

start() {
set_class(5);
set_name("hood");
set_short("A dark green hood");
set_long(
"This hood is made of a soft thick fabric and feels warm to the touch.\n"+
"It once belonged to a revered huntmaster and is rumoured to have an\n"+
"envigorating effect on its owner.\n");

set_stats("str", 4);
set_stats("dex", 4);
set_stats("con", 2);

set_value(1000);
set_weight(500);
set_slot("head");
}

