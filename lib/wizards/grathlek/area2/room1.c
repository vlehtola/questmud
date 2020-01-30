inherit "room/room";
object monster; 
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/grathlek/area2/monsies/guard.c");
    move_object(monster, this_object());
  }
  add_exit("east","/wizards/grathlek/area2/room2.c");
  add_exit("path","/wizards/grathlek/workroom.c");
  
  short_desc = "Entrance to the town of Tristram";
  long_desc = "You are standing on the road to town of\n"+
              "Tristram. You can feel great fear in \n"+
              "the air.\n"; 
}
