inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/ispep-4");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/cit3");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/walla/jericho/rooms/ispep-5");
  add_exit("east","wizards/walla/jericho/rooms/ispep-3");
  short_desc = "On Ispep street";
  long_desc =
"Ispep street is one of the main roads of Jericho. It follows an east west\n" +
"direction, and splits the town into two almost as big halves. The road has been\n" +
"recently paved, with heavy marble, to prevent vermins and other creatures from\n" +
"surfacing from the underground.\n";
}

