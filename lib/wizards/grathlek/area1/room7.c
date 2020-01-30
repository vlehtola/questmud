inherit "room/room";
object monster; 
 
reset(arg) {
  if(!monster) {
    if(arg) return;
    monster = clone_object("/wizards/grathlek/area1/monsies/snake.c"); 
    move_object(monster, this_object());
  }
  add_exit("southeast","/wizards/grathlek/area1/room13.c");
  add_exit("west","/wizards/grathlek/area1/room6.c");
 
  
  short_desc = "Path goes southeast and west.";
  long_desc = "The temple shimmers in strange light. Dark forest\n"+
              "is against the temple. But even the darkness in\n"+
              "the forest faints away from the strange light.\n";

}
