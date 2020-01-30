inherit "room/room";
object monster; 
 
reset(arg) {
  if(!monster) { 
   monster = clone_object("/wizards/grathlek/area1/monsies/guard.c");
   move_object(monster, this_object());
  }
  add_exit("north","/wizards/grathlek/area1/room3.c");
  add_exit("south","/wizards/grathlek/area1/room27.c");
  add_exit("west","/wizards/grathlek/area1/room1.c");
  add_exit("enter","/wizards/grathlek/area1/eroom1.c");
  
  short_desc = "Entrance to the Temple of Eternal Light";
  long_desc = "The great temple shimmers in some kind of strange light.\n"+
              "There is light coming from the temple's tower.\n"+
              "The entrance to the temple is right here.\n"; 
}
