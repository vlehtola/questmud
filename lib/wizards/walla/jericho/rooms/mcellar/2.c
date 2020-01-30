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
    monster = clone_object("/wizards/walla/jericho/mobs/uhrac");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/walla/jericho/rooms/mcellar/3");
  short_desc = "In a faintly lit cavern";
  long_desc =
"You have entered a faintly lit cavern, deep beneath the city. It looks as\n" +
"if the place has been here for some while. The air smells of sulphur and death,\n" +
"and the ground is covered with red coloured dust. Some water seems to be leaking\n" +
"through the limestone walls.\n";
}



