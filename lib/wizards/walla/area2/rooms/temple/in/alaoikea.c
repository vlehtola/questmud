inherit "room/room";
 
object monsu;
 
reset(arg) {
   if(!monsu) {
    monsu = clone_object("/wizards/walla/area2/mobs/wmonk");
    move_object(monsu, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/walla/area2/rooms/temple/in/oikeakeski");
  add_exit("west","wizards/walla/area2/rooms/temple/in/alakeski");
  add_exit("northwest","wizards/walla/area2/rooms/temple/in/keski");
  short_desc = "The Gate to the temple";
  long_desc =
"The gates to the castle lie before you, and rise to the sky like two\n" +
"big pillars. Across them is lies a beautifully carved dragon, which\n" +
"seems to look you right into your eyes.\n";
 
 
 }
