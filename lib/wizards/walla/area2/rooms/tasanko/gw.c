inherit "room/room";
 
object monster,monster2;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/area2/mobs/porttivahti");
    move_object(monster, this_object());
  }
  if(!monster2) {
    monster = clone_object("/wizards/walla/area2/mobs/porttivahti");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/walla/area2/rooms/tasanko/cs");
  add_exit("north","wizards/walla/area2/rooms/tasanko/piha/alakeski");
  short_desc = "The Gate to the temple";
  long_desc =
"The gates to the castle lie before you, and rise to the sky like two\n" +
"big pillars. Across them is lies a beautifully carved dragon, which\n" +
"seems to look you right into your eyes.\n";
 

 }





