inherit "room/room";
 
  reset(arg) {
 
  add_exit("west","/wizards/walla/area2/rooms/tasanko/garden/alavasen");
  add_exit("east","/wizards/walla/area2/rooms/tasanko/garden/alaoikea");
  short_desc = "In the garden of meditation";
  long_desc =
"The garden of meditation is a quiet place. Even the birds\n" +
"shun this place. Even you halt for a moment to admire the\n" +
"extreme silence and soothing feeling of this place.\n";
 
  property = allocate(4);
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
 
}

