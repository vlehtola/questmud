inherit "room/room";
object monster; 
 
 
reset(arg) {
  if(!monster) { 
  monster = clone_object("/wizards/grathlek/area1/monsies/paladin.c");
  move_object(monster, this_object());
  }
  add_exit("east","/wizards/grathlek/area1/eroom7.c");
  add_exit("north","/wizards/grathlek/area1/eroom6.c");
  add_exit("west","/wizards/grathlek/area1/eroom4.c");
  add_exit("northeast","/wizards/grathlek/area1/eroom8.c");
  
  
  short_desc = "In the training halls of the temple.";
  long_desc = "You area standing on the training halls of the temple.\n"+
              "There is a test dummy in the center of room where\n"+ 
              "paladins can test their special moves and spells.\n";              
               
items = allocate(4);
  items[0] = "dummy";
  items[1] = "A test dummy, it's seems to be on hard use\n"+
             "of the paladins. It has many holes and crack's";

}
