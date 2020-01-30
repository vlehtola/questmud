inherit "room/room";
 
object monster,tuli;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/area2/mobs/rogue");
    move_object(monster, this_object());
}
  if(!tuli) {
    tuli = clone_object("/wizards/walla/area2/stuph/campfire");
    move_object(tuli, this_object());
}  


  if(arg) return;
  add_exit("east","wizards/walla/area2/rooms/ricefield/cave/6");
  short_desc = "A dead end";
  long_desc =
"The room is lit up by a campfire.\n" +
"ja lisaa siistii schtuffia\n" +
"sitten ku oon jurrissa,\n" +
"ja pystyn keksii parempia\n" +
"long desceja.\n";
 
}

