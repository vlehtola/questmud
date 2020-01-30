inherit "obj/armour";

start() {
  set_class(4);
  set_slot("cloak");
  set_name("cleric robe");
  set_alias("robe");
  set_short("Robe of the Cleric");
  set_long("This is one of the robes made to suite the cleric.\n"+
           "It is all black with the picture of a grasping han on the back.\n");
  set_value(10000);
  set_weight(500);
  set_stats("int", 19);
  set_stats("wis", 13);
  set_stats("spr", 25);
  set_stats("str", -14);
  set_stats("dex", -15);
  set_stats("con", 12);
}
