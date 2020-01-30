inherit "room/room";
 
object cage;
 
reset(arg) {
  if(!cage) {
    cage = clone_object("/wizards/walla/northern/mobs/iglak");
    move_object(cage, this_object());
  }
  if(arg) return;
  add_exit("south","22");
  add_exit("north","25");
  short_desc = "In a dark passage under the mountain";
  long_desc =
"The passage that you see before you, reminds you oddly of a prison. There are bars\n" +
"and chains hanging of the wall. The paraphernalia on the walls seem to have been\n" +
"abandoned for quite some time now. Still, voices can be heard from the depths of\n" +
"the mountain.\n";
 
 
}

