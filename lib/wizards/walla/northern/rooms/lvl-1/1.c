inherit "room/room";
 
 
reset(arg) {
 
  add_exit("up","/wizards/walla/northern/rooms/lvl1/se3");
  add_exit("south","/wizards/walla/northern/rooms/lvl-1/2");
  items = allocate(2);
  items[0] = "stairs";
  items[1] = "Stairs leading up to the main floor";
  short_desc = "In a dark passage under the mountain";
  long_desc =
"The passage that you see before you, reminds you oddly of a prison. There are bars\n" +
"and chains hanging of the wall. The paraphernalia on the walls seem to have been\n" +
"abandoned for quite some time now. Still, voices can be heard from the depths of\n" +
"the mountain.\n";
 
 
}
