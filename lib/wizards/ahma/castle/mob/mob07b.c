inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(5)+25);
  set_name("flesh maggot");
  set_alias("maggot");
  set_short("Huge flesh maggot");
  set_long("A discusting worm crawls out from the ground and attacks you as soon as it\n" + 
           "senses your presence. The glowing, slimy worm is about two feet long and\n" + 
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
