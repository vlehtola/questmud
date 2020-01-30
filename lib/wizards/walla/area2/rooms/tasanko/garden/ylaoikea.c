inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/area2/mobs/furukitsune");
    move_object(monster, this_object());
  }
 
  if(arg) return;
  add_exit("west","wizards/walla/area2/rooms/tasanko/garden/ylakeski");
  add_exit("south","wizards/walla/area2/rooms/tasanko/garden/oikeakeski");
  short_desc = "The garden of meditation";
  long_desc =
"The garden of meditation is a quiet place. Even the birds\n" +
"shun this place. Even you halt for a moment to admire the\n" +
"extreme silence and soothing feeling of this place.\n";
 
 
  property = allocate(2);
  property[0] = "no_skill";
  property[1] = "no_spell";
 
}
 
 
