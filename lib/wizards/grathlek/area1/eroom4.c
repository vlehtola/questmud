inherit "room/room";
object monster; 
 
 
reset(arg) {
  if(!monster) { 
  monster = clone_object("/wizards/grathlek/area1/monsies/paladin.c");
  move_object(monster, this_object());
  }
  add_exit("east","/wizards/grathlek/area1/eroom5.c");
  add_exit("west","/wizards/grathlek/area1/eroom3.c");
  
  short_desc = "Shimmering hallway of the temple.";
  long_desc = "Walls of the hallway shimmers in stranger\n"+
              "light it seems to that light is all over\n"+
              "this temple. Hallway leads to east and west.\n";
              
               
 

}
