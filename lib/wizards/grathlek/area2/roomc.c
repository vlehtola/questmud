inherit "room/room";
object monster; 
 
 
reset(arg) {
   if(!monster) { 
    monster = clone_object("/wizards/grathlek/area2/monsies/cain.c");
    move_object(monster, this_object());
  }     
  add_exit("east","/wizards/grathlek/area2/room7.c");
  add_exit("north","/wizards/grathlek/area2/room11.c");
  add_exit("south","/wizards/grathlek/area2/room16.c");
  add_exit("west","/wizards/grathlek/area2/room6.c");
  set_light(2);
  
  short_desc = "In the central square of Tristram.";
  long_desc = "You are standing on the central square of Tristram.\n"+
              "This is the place where peapole usually gather .\n"+
              "for a chat or listen to Cains advices.\n";
}
