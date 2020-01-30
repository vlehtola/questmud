inherit "obj/armour";
start() {
  set_class(8);
  set_sub_type("plate mail");
  set_name("plate");
  set_short("A stone reinforced steel plate mail");
  set_long("On the first glance this piece of armour seems to be fully made of stone,\n" +
           "but longer examination shows that from inside the armour is made of steel\n" +
           "and the stony layer has been added later. Weak blue light is shimmering\n" +
           "from the holes between the stones, like the armour would possess some\n" +
           "magical enchantments. Due to the stones the armour feels very heavy,\n" +
           "but they weaken even the most powerful blow aimed for the wearer's torso");

  set_stats("str", 5);
  set_stats("dex", -4);
  set_stats("con", 4);
  set_stats("spr", -5);
  set_resists("fire", 7);
  set_resists("electric", 7);
}
