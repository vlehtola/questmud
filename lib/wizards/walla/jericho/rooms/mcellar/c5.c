inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/nomap");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/prisoner1");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/walla/jericho/rooms/mcellar/6");
  short_desc = "A small prison cell";
  long_desc =
"You are standing in a small prison cell. The room has a horrid smell, from a mixture\n" +
"of urin, excrements, vomit and blood. The smell makes you feel nauseous, and you the\n" +
"and the only thought is how, or when you could leave this place.\n";
}


