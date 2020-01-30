inherit "room/room";


object monster,monster2;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/imp");
    move_object(monster, this_object());
if(!monster2) { 
    monster2 = clone_object("/wizards/veron/areat/golem/mobs/imp");
    move_object(monster2, this_object());
}
}

add_exit("south","/wizards/veron/areat/golem/room16.c");



  short_desc = "A storage";

  long_desc = "A small room which is full of firewood. The floor is completely\n"+
		  "covered with small pieces of wood and splinters. There's a large\n"+
		  "log on the floor with an ax on it. Some saws have been hang up\n"+
		  "on the walls.\n";
              
		  
  items = allocate(6);
  items[0] = "log";
  items[1] = "A large log which is used when chopping wood";
  items[2] = "ax";
  items[3] = "A rather small ax which is used in chopping wood";
  items[4] = "saws";
  items[5] = "Several saws hanging on the walls";
 set_not_out(1);
		
  }
