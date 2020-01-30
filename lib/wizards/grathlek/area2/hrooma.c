inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area2/monsies/adrel.c");
    move_object(monster, this_object());
   }
  add_exit("south","/wizards/grathlek/area2/hrooms.c");
  add_exit("west","/wizards/grathlek/area2/hroom7.c");
  set_light(0); 
  
  short_desc = "In the guardian room.";
  long_desc = "This is the guardian room. There is a large\n"+
              "chair on the center of this room.\n"+
              "You can feel presense of great evil.\n"+
              "It is really cold and dark in here.\n"; 


  items = allocate(4);
    items[0] = "chair"; 
    items[1] = "This chair is made of bone.\n";
}
