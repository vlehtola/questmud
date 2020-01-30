inherit "obj/armour";

start() {
  set_class(4);
  set_slot("cloak");
  set_name("mage robe");
  set_alias("robe");
  set_short("Robe of the Mage");
  set_long("This is one of the robes made to suite the mage.\n"+
           "It is all in blue with some stars outlined in red.\n");
  set_value(10000);
  set_weight(500);
  set_stats("int", 10);
  set_stats("wis", 17);
  set_stats("spr", 25);
  set_stats("str", -10);
  set_stats("dex", -10);
}
