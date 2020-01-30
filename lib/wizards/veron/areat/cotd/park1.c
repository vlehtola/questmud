inherit "room/room";



object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/cotd/mobs/duck");
    move_object(monster, this_object());
  }

add_exit("east","/wizards/veron/areat/cotd/cs.c");



  short_desc = "A park";

  long_desc = "A park which has probably been green and verdant, but now\n"+
              "the desert has taken back it's own. Sand covers the grass\n"+
	      "and water in the pond is brown and dirty. The once-green\n"+
              "birch trees are dead and leafless. A dust-covered path leads\n"+
              "east back to the main street. There's a bench growing moss\n"+
              "near the pond.\n";
            
              

  items = allocate(8);
  items[0] = "pond";
  items[1] = "A small pond. The water is muddy and thick";
  items[2] = "tree";
  items[3] = "Dead, leafless birch trees";
  items[4] = "path";
  items[5] = "Dusty path leading back to the main street";
  items[6] = "bench";
  items[7] = "The moss-growing bench is placed near the pond";
 
 	
  }
