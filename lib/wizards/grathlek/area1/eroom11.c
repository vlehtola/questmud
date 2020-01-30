inherit "room/room";
object monster; 
 
 
reset(arg) {
  if(!monster) { 
  monster = clone_object("/wizards/grathlek/area1/monsies/paladin.c");
  move_object(monster, this_object());
  }
  add_exit("west","/wizards/grathlek/area1/eroom9.c");
  add_exit("northeast","/wizards/grathlek/area1/eroom12.c");

  
  
  short_desc = "In the training halls of the temple.";
  long_desc = "You are standing on the training halls of the temple\n"+
              "There is a test dummy in the center of the room where "+ 
              "paladins can test their special moves and spells.\n";
              
               
items = allocate(4);
  items[0] = "dummy";
  items[2] = "A test dummy seems to be on hard use of the\n"+
             "paladins. It hast many holes and crack's\n";

}
