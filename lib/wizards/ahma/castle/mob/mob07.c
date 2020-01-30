inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(5)+12);
  set_name("flesh maggot");
  set_alias("maggot");
  set_short("Small flesh maggot");
  set_long("A disgusting worm crawls out from the ground and seems to sense your presence\n" + 
           "as soon as it appears. The glowing, slimy worm is about two feet long and\n" + 
           "somewhat plump. It has a circular-like mouth, and it's full of teeth. There\n" + 
           "must be four or five rows of them. The main food for these worms is meat. The\n" + 
           "fact becomes clear to you as you notice a piece of human meat and skin caught\n" + 
           "onto this creature's numerous teeth. The maggot is attacking you totally blind,\n" + 
           "but to compensate its missing sight, it has developed its other senses to pull\n" + 
           "at the difference in number of them.\n");
  set_al(0);
  set_aggressive(1);
  set_animal(1);
}
