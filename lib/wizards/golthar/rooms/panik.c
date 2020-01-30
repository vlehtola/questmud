inherit "room/room";

reset(arg) {
  
  if(arg) return;
  add_exit("south","/wizards/golthar/workroom");
  short_desc = "Testing and panic room";
  long_desc = "You have ran into a room which is ment\n"
              "for panic situations. Do Not stay long\n"
              "or someone might get angry.\n";
  property = allocate(1);
  property[0] = "no_summon";
}
