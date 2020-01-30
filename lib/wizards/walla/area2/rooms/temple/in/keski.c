inherit "room/room";
 
object pytty;
 
reset(arg) {
  if(!pytty) {
    pytty = clone_object("/wizards/walla/area2/stuph/pytty.c");
    move_object(pytty, this_object());
  }
 
  if(arg) return;
  add_exit("south","/wizards/walla/area2/rooms/temple/in/alakeski");
  add_exit("north","/wizards/walla/area2/rooms/temple/in/ylakeski");
  add_exit("southwest","/wizards/walla/area2/rooms/temple/in/alavasen");
  add_exit("southeast","/wizards/walla/area2/rooms/temple/in/alaoikea");
  add_exit("east","/wizards/walla/area2/rooms/temple/in/oikeakeski");
  add_exit("west","/wizards/walla/area2/rooms/temple/in/vasenkeski");
  add_exit("northeast","/wizards/walla/area2/rooms/temple/in/ylaoikea");
  add_exit("northwest","/wizards/walla/area2/rooms/temple/in/ylavasen");
  short_desc = "In the courtyard";
  long_desc =
"In the middle of the courtyard, there lies a huge cauldron, that burns \n" +
"with an eternal fire. It seems that no one needs to add accelerant to \n" +
"the cauldron. \n";
 
}
