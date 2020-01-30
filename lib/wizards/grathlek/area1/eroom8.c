inherit "room/room";
object monster; 
 
 
reset(arg) {
  if(!monster) { 
  monster = clone_object("/wizards/grathlek/area1/monsies/paladin.c");
  move_object(monster, this_object());
  }
  add_exit("east","/wizards/grathlek/area1/eroom10.c");
  add_exit("west","/wizards/grathlek/area1/eroom6.c");
  add_exit("south","/wizards/grathlek/area1/eroom7.c");
  add_exit("southeast","/wizards/grathlek/area1/eroom9.c");
  add_exit("southwest","/wizards/grathlek/area1/eroom5.c");
  
  
  short_desc = "In the training halls of the temple.";
  long_desc = "You are standing on the traning halls of the temple.\n"+
              "There is a test dummy in the center of the room where\n"+ 
              "paladins can test their special moves and spells.\n";
        
items = allocate(4);
  items[0] = "dummy";              
  items[1] = "A test dummy it's seems to be on hard use of the\n"+             
             "paladins. It has many holes and crack's.\n";
}
