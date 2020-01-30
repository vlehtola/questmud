inherit "room/room";
object monster;

 
reset(arg) {
  if(!monster) {
  monster = clone_object("/wizards/grathlek/area1/monsies/fox.c");
  move_object(monster, this_object());
  }
  add_exit("east","/wizards/grathlek/area1/room5.c");
  add_exit("southwest","/wizards/grathlek/area1/room3.c");
 
  
  short_desc = "Path goes east and southwest from here.";
  long_desc = "The temple shimmers in strange light. Dark forest\n"+
              "is against the temple. But even the darkness in the \n"+
              "forest faint's away from the strange light.\n"; 
 

}
