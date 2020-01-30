inherit "obj/armour";

start() {
  set_class(2);
  set_slot("cloak");
  set_name("priest cloak");
  set_alias("cloak");
  set_short("A second circle priest cloak");
  set_long("This cloak is one of the cloaks given to the\n"+
           "priest's of the second circle and they shine with a dull glow.\n");
  set_value(500);
  set_weight(500);
  set_stats("int", 2);
  set_stats("wis", 2);
}
