inherit "room/room";
object monster; 
 
 
reset(arg) {
  if(!monster) { 
   if(arg) return;
  monster = clone_object("/wizards/grathlek/area1/monsies/guard2.c");
  move_object(monster, this_object());
  }
  add_exit("south","/wizards/grathlek/area1/eroom2.c");
  add_exit("enter","/wizards/grathlek/area1/nroom2.c");
  
  short_desc = "There is A door. The corriodor turns back to south";
  long_desc = "There is A door to Master Leornics room the corridor turns back south.\n"+
              "Door is open. There is a picture of Master Leornic on the west wall\n"+
              "of the corridor.\n"; 
              
               
 

}
