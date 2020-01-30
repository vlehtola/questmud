inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/ispep-2");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/cit3");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/walla/jericho/rooms/ispep-2");
  add_exit("east","wizards/walla/jericho/rooms/cs");
  add_exit("north","wizards/walla/jericho/rooms/graveyard/entrance");
  add_exit("south","wizards/walla/jericho/rooms/mayor1");
  short_desc = "On Ispep street";
  long_desc =
"Ispep street is one of the main roads of Jericho. It follows an east west\n" +
"direction, and splits the town into two almost as big halves. The road has been\n" +
"recently paved, with heavy marble, to prevent vermins and other creatures from\n" +
"surfacing from the underground. To the north lies a spooky place, the cemetary\n";
}
