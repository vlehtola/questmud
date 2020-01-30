inherit "room/room";
 
object key;
 
reset(arg) {
  if(!key) {
    key = clone_object("/wizards/walla/northern/stuph/key");
    move_object(key, this_object());
  }
  if(arg) return;
  add_exit("north","mainhall21");
  short_desc = "A hidden room";
  long_desc =
  long_desc =
"A small hidden room, behind the wall. There is really not much to see here, but it\n" +
"looks like this room has been previously visited, due to footsteps in the dust that\n" +
"covers the ground.\n";
 
}

