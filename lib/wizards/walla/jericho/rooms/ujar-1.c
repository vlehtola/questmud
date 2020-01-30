inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/ujar-1");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/cit1");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/walla/jericho/rooms/ujar-2");
  add_exit("south","wizards/walla/jericho/rooms/cs");
  add_exit("east","wizards/walla/jericho/rooms/mosque1");
  short_desc = "On Ujar street";
  long_desc =
"You are standing on Ujar street, one of the main roads in Jericho.\n" +
"To the south lies the Grande Place, which connects the two major\n" +
"roads in the city. Further north, you can see the town walls, and to\n" +
"the east is the mosque, where people can go and pray. It is one of the \n" +
"only buildings that still remain untouched.\n";
 
}
