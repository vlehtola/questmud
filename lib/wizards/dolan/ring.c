inherit "obj/armour";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_class(1);
set_name("fireringuli");
set_short("A red ring of brotherhood");
set_long("This is the ring of secret keeper Drazil.\n"+
"It is really beautifully and there is a huge shaphire on it.");
set_weight(1);
set_value(1000);
set_alias("ring");
}
