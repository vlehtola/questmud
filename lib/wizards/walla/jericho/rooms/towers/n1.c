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
    monster = clone_object("/wizards/walla/jericho/mobs/towerguard1");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/walla/jericho/rooms/ujar-4");
  add_exit("up","wizards/walla/jericho/rooms/towers/n2");
  short_desc = "At the bottom of a huge stairwell";
  long_desc =
"You are standing at the bottom of some stairs, leading upwards, to the top\n" +
"of the northern guardtower. In front of the stairwell stands a monster of\n" +
"a man, at least 7 feet tall, armed to the teeth. He seems keen on not letting\n" +
"you pass, as what lies beyond the stairwell is none of your business.\n";
 
}
