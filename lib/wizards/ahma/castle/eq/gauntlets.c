inherit "obj/armour";
start() {
  set_class(6);
  set_value(5000);
  set_sub_type("chain gauntlets");
  set_short("Sturdy bone gauntlets");
  set_long("These gauntlets have been carved from solid bone. On the gauntlets there seems\n" + 
           "to be small crater-like holes, which tells from large-sized bone porouses. The\n" + 
           "bigger the porouses in bones, the bigger the creature who owns the bone.\n" + 
           "So, obviously these gauntlets have been made from bones of a huge demon-animal.\n" + 
           "Gauntlets are painted, probably with blood, light reddish and some chains have\n" + 
           "been attached to them to make decoration. In addon, the gauntlets seem to be\n" + 
           "surrounded by a blue, magical enchantment aura");
  set_stats("str", 4);
  set_stats("dex", 3);
  set_stats("con", 5);
  set_stats("int", -6);
  set_stats("spr", -3);
  set_resists("fire", 8);
  set_resists("cold", 8);
  set_resists("electric", 8);
}
