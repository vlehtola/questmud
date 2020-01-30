inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/northern/mobs/helof");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","17");
  add_exit("west","15");
  short_desc = "In a dark passage under the mountain";
  long_desc =
"The passage that you see before you, reminds you oddly of a prison. There are bars\n" +
"and chains hanging of the wall. The paraphernalia on the walls seem to have been\n" +
"abandoned for quite some time now. Still, voices can be heard from the depths of\n" +
"the mountain.\n";
 
 
}


