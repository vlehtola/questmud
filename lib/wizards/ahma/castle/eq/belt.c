inherit "obj/armour";
start() {
  set_value(900);
  set_name("belt");
  set_short("A red stone belt");
  set_long("You have never seen a belt like this before. It is fully made of glowing stones\n" + 
           "attached to each other with durable strips of demon skin. As you quickly count,\n" + 
           "the belt seems to consist of at least fifteen pieces of stone. And as you might\n" + 
           "think, it is much heavier than normal belts, even more heavier than some torso\n" + 
           "armours. The stones' strong red shimmering is mixed with a weak blue glow from\n" + 
           "some enchantment spell laid upon the belt");
  set_slot("belt");
  set_weight(1000);
  set_stats("str", 2);
  set_stats("dex", -10);
  set_stats("con", 3);
  set_stats("spr", 6);
}
