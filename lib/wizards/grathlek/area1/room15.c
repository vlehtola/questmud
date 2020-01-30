inherit "room/room";
object monster; 
 
 
reset(arg) {
   if(!monster) { 
    if(arg) return;
    monster = clone_object("/wizards/grathlek/area1/monsies/mopriest.c");
    move_object(monster, this_object());
  }
  add_exit("south","/wizards/grathlek/area1/room16.c");
  add_exit("north","/wizards/grathlek/area1/room14.c");
 
  
  short_desc = "Path goes south and north.";
  long_desc = "The temple shimmers in strange light. Dark forest\n"+
              "is against the temple. But even the darkness in the \n"+
              "forest faint's away from the strange light.\n"; 
 

}
