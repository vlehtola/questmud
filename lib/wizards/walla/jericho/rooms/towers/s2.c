inherit "room/room";
 
void init() {
::init();
call_other("/wizards/walla/jericho/rooms/towers/explore_d.c","check_rooms",this_object());
}
 
object monster;
 
reset(arg) {
  if(arg) return;
  add_exit("down","wizards/walla/jericho/rooms/towers/s1");
  short_desc = "in the tower";
  long_desc =
"Ispep street is one of the main roads of Jericho. It follows an east west\n" +
"direction, and splits the town into two almost as big halves. The road has been\n" +
"recently paved, with heavy marble, to prevent vermins and other creatures from\n" +
"surfacing from the underground. To the north lies a spooky place, the cemetary\n";
}
