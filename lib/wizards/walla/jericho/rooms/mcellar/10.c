inherit "room/room";
 
init() {
  ::init();
  add_action("climb", "climb");
}
 
climb(str) {
  if(str != "ladder") return;
  write("You climb up the ladder.\n");
  say(""+this_player()->query_name()+" climbs up the ladder.\n");
  move_object(this_player(),"/wizards/walla/jericho/rooms/graveyard/33");
  command("look");
  return 1;
}
 
reset(arg) {
  add_exit("north","/wizards/walla/jericho/rooms/mcellar/9");
  short_desc = "In a faintly lit cavern";
  long_desc =
"You are in a faintly lit cavern, deep beneath the city. It looks as\n" +
"if the place has been here for some while. The air smells of sulphur and death,\n" +
"and the ground is covered with red coloured dust. Some water seems to be sippring\n" +
"through the limestone walls. A ladder stands by the wall. Maybe you could climb it?\n";
}



