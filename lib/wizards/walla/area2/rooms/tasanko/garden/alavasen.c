inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/area2/mobs/twin");
    move_object(monster, this_object());
  }
 
  if(arg) return;
  add_exit("southwest","wizards/walla/area2/rooms/tasanko/gardenway2");
  add_exit("north","wizards/walla/area2/rooms/tasanko/garden/vasenkeski");
  add_exit("east","wizards/walla/area2/rooms/tasanko/garden/alakeski");
  short_desc = "The garden of meditation";
  long_desc =
"The garden of meditation is a quiet place. Even the birds\n" +
"shun this place. Even you halt for a moment to admire the\n" +
"extreme silence and soothing feeling of this place.\n";
 
}

