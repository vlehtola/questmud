inherit "room/room";


object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/egolem");
    move_object(monster, this_object());
  }

add_exit("south","/wizards/veron/areat/golem/room5.c");

  short_desc = "A stinking cellar";

  long_desc = "The cellar is very moist in here. The wooden supporting pillars\n"+
		  "seem to be rotten. There's a large tub of rotten potatoes in\n"+
		  "the corner. Some broken tools lie in the middle of the room.\n"+
		  "It's almost dark in here, the only light is coming from \n"+
		  "small cracks in the ceiling.\n";
		
		 
  items = allocate(4);
  items[0] = "tub";
  items[1] = "A tub full of rotten potatoes";
  items[2] = "tools";
  items[3] = "A broken saw, axe and hammer, all broken and useless";
set_not_out(1);		
  }
