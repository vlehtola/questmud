inherit "obj/armour";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_class(1);
set_name("weddingring");
set_short("A Golden Wedding Ring");
set_long("It is a symbol of Love.\n"+
"It is made out of pure gold.");
set_weight(1);
set_slot("finger");
set_alias("ring");
}
