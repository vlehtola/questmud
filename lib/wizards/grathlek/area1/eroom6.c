inherit "room/room";
object monster; 


reset(arg) {
  if(!monster) { 
  monster = clone_object("/wizards/grathlek/area1/monsies/paladin.c");
  move_object(monster, this_object());
  }
  add_exit("east","/wizards/grathlek/area1/eroom8.c");
  add_exit("south","/wizards/grathlek/area1/eroom5.c");
  add_exit("southeast","/wizards/grathlek/area1/eroom7.c");
  
  
  short_desc = "In the training halls of the temple.";
  long_desc = "You are standing on the training halls of the temple\n"+
              "There is a test dummy in the center of this room where\n"+ 
              "paladins can test their special moves and spells.\n";
  
items = allocate(4);
  items[0] = "dummy";
  items[1] = "A test dummy seems to be on hard use of the\n"+
             "paladins. It has many holes and crack's.\n";  
 

}
