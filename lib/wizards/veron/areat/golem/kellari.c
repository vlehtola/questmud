inherit "room/room";



object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/guard");
    move_object(monster, this_object());
  }

add_exit("southeast","/wizards/veron/areat/golem/room3.c");
add_exit("ladder","/wizards/veron/areat/golem/kellari2.c");

  short_desc = "A small room";

  long_desc = "A very small room. The granite walls are slimy and wet.\n"+
              "There's an old wooden bench in the northeastern corner.\n"+
              "A small dirty rag is on the floor. A wooden torch burns\n"+
		  "brightly on the wall.\n";
		  
  items = allocate(6);
  items[0] = "torch";
  items[1] = "A wooden torch burning brightly";
  items[2] = "bench";
  items[3] = "An old wooden bench is placed in the northeastern corner. It has a large\n"+
		 "crack in its surface";
  items[4] = "rag";
  items[5] = "A small dirty rag. It's color can't be identified";
 set_not_out(1);
		
  }