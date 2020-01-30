inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/map");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/pcit");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/walla/jericho/rooms/ujar-1");
  add_exit("east","wizards/walla/jericho/rooms/mosque2"); 
  short_desc = "In the mosque";
  long_desc =
"You have arrived in the mosque of Jericho. The air in here is a lot\n" +
"cooler than the air outside, and a faint smell of incese can be distinguished\n" +
"in the air. You can see the roof, some 30 feet up in the air, and there is a\n" +
"chandelier hanging from one of the beams in the ceiling. Curtains are blocking\n" +
"windows, keeping the room adequatly dark.\n";
 
}
