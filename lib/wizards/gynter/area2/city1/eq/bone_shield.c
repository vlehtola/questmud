inherit "obj/weapon";

start() {
  set_class(7);
  set_sub_type("large shield");
  set_short("A bone shield");
  set_long("This is one of the legendary bone shields that are crafted\n"+
           "from the bones of the mightyest warriors that has walked this realm");
  set_value(10000);
  set_stats("str", 15);
  set_stats("dex", 15);
  set_stats("hpr", 29);
  set_stats("int", -15);
  set_stats("wis", -15);
  set_Stats("spr", -25);
  set_stats("con", 18);
}
