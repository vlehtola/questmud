inherit "obj/weapon";

start() {
  set_class(7);
  set_sub_type("great axe");
  set_short("A bone axe");
  set_long("This is one of the best axe's that has been created in\n"+
           "the land of eternal darkness, death");
  set_value(10000);
  set_stats("str", 15);
  set_stats("dex", 5);
  set_stats("hpr", 25);
  set_stats("int", -10);
  set_stats("wis", -10);
  set_stats("con", 12);
}
