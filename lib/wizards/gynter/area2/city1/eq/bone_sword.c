inherit "obj/weapon";

start() {
  set_class(7);
  set_sub_type("broad sword");
  set_short("A bone sword");
  set_long("This is a sword made out of the strongest bones that exist in\n"+
           "the land of the dead");
  set_value(10000);
  set_stats("str", 19);
  set_stats("dex", 20);
  set_stats("hpr", 15);
  set_stats("int", -15);
  set_stats("wis", -20);
  set_stats("con", 18);
}
