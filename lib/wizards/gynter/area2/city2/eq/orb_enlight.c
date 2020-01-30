inherit "obj/armour";

start() {
  set_slot("held");
  set_name("orb of enlightment");
  set_alias("orb");
  set_short("Orb of enlightment");
  set_long("This is one of the Orbs of Enlightment. They are the ultimate equipment\n"+
           "for a spellcaster.\n");
  set_value(10000);
  set_weight(500);
  set_stats("wis", 16);
  set_stats("int", 15);
  set_stats("spr", 24);
  set_stats("str", -15);
  set_stats("dex", -10);
  set_stats("hpr", -15);
}
