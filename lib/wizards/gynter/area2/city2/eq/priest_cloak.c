inherit "obj/armour";

start() {
  set_class(2);
  set_slot("cloak");
  set_name("priest cloak");
  set_alias("cloak");
  set_short("A first circle priest cloak");
  set_long("This cloak is one of the cloaks given to the\n"+
           "priest's of the first circle and they aren't that special.\n");
  set_value(400);
  set_weight(500);
  set_stats("int", 2);
}
