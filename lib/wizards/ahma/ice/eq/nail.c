inherit "obj/armour";

start() {
  set_slot("finger");
  set_name("fingernail");
  set_alias("nail");
  set_short("A brown platinum fingernail");
  set_long("A sharp, long fingernail has been carved out of platinum and attached to\n" +
           "a platinum ring. The nail-ring combination is not designed to be used as\n" +
           "a weapon because of its soft material, which would twist and crack in a\n" +
           "minute. But while lacking the raw offensive value, the fingernail seems\n" +
           "to possess more of the magical one. Thin layer of blood covers the nail,\n "+
           "efficiently blocking the original colour of platinum from being visible");

  
  set_stats("str", 2);
  set_stats("dex", 3);
  set_stats("con", 1);
  set_value(1500);
  set_weight(30);
}