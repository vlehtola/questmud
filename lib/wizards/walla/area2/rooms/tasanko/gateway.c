inherit "room/room";
 
object monster,monsu;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/area2/mobs/porttivahti");
    move_object(monster, this_object());
  }
  if(!monsu) {
    monsu = clone_object("/wizards/walla/area2/mobs/porttivahti");
    move_object(monsu, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/walla/area2/rooms/tasanko/cs");
  add_exit("north","wizards/walla/area2/rooms/temple/in/alakeski");
  short_desc = "The Gate to the temple";
  long_desc =
"The gates to the castle lie before you, and rise to the sky like two\n" +
"big pillars. Across them is lies a beautifully carved dragon, which\n" +
"seems to look you right into your eyes.\n";
 
 
 }
