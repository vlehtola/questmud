inherit "obj/armour";
start() {
  set_slot("neck");
  set_name("amulet");
  set_short("A shiny amulet of the Beast");
  set_long("The pentagon-shaped amulet weights amazingly little despite of its big\n" +
           "size. Amulet is made of some unfamiliar metal, it looks like gold, but is\n" +
           "much lighter and cooler to the touch. On the frontside of the amulet there\n" +
           "seems to be illustrated numerous different predators. Amulet's backside\n" +
           "is filled with words made of crude carvings. The predators on the frontside\n" +
           "of the amulet picture a few familiar predators like wolf, wolverine, eagle\n" +
           "and shark. The rest of the small pictures cannot be recognized. A string\n" +
           "made of skin is attached to the upper part of the amulet, making it possible\n" +
           "to wear the amulet around the neck");

  set_weight(50);
  set_value(5000);
  set_stats("str", 7);
  set_stats("dex", -2);
  set_stats("con", 5);
  set_stats("spr", -10);
}