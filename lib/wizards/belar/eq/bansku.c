inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
	set_name("banana");
	set_alias("fruit");
	set_short("A delicious looking banana");
	set_long("The fruit looks delicious. It has a shape of long, \n");
set_weight(250);
set_value(10);
set_strength(1000);
}

