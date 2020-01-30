inherit "obj/armour";
start() {
  set_slot("finger");
  set_name("ring");
  set_short("A glowing stone ring named 'Stone Barrage'");
  set_long("Strong feeling of victory fills you near this stony ring which glows\n" +
           "weakly. Some rumors tell that this and few other rings gained their\n" +
           "superior constitutional powers in the Great Earth Elemental War, which\n" +
           "took place some eight hundred years ago. The ring weights quite much\n" +
           "for an item of its size, but the sturdy stone, from which it has been\n" +
           "made, explains it. The bluish-grey glow which the ring is emitting\n" +
           "seems to lay some courage on you");
  
  set_value(5000);
  set_weight(100);
  set_stats("str", 3);
  set_stats("dex", -3);
  set_stats("con", 8);
  set_stats("spr", -8);
}