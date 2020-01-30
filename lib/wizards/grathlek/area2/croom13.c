inherit "room/room";
object monster; 

 
reset(arg) {
   if(!monster) { 
    monster = clone_object("/wizards/grathlek/area2/monsies/car.c");
    move_object(monster, this_object());
  }
  add_exit("south","/wizards/grathlek/area2/croom6.c");
  add_exit("west","/wizards/grathlek/area2/croom12.c");
  set_light(0); 
  
  short_desc = "In the dark cathedral.";
  long_desc = "You are standing on the corridors of.\n"+
              "the dark cathedral Kahnduras.\n"+
              "It's very dark and cold here.\n"; 
 

}
