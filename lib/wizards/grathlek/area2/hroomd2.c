inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area2/monsies/hscav.c");
    move_object(monster, this_object());
   }
  add_exit("west","/wizards/grathlek/area2/hroom19.c");
  set_light(0); 
  
  short_desc = "A dead end.";
  long_desc = "This is a dead end. It is really\n"+
              "cold and dark in here.\n"; 
}
