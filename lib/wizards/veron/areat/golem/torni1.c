inherit "room/room";


object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/guard");
    move_object(monster, this_object());

}

add_exit("west","/wizards/veron/areat/golem/room17.c");
add_exit("up","/wizards/veron/areat/golem/torni2.c");




  short_desc = "A round room with stairs";

  long_desc = "This is a rather small, round room with spiral stairs leading \n"+
		  "upstairs. A large bear pelt is placed in front of the stairs.\n"+
		  "There's a small, round window in the northern wall. It has metal\n"+
		  "bars in it. An old, cracked wooden bench is left leaning to the\n"+
		  "southern wall.\n";              
		  
  items = allocate(6);
  items[0] = "pelt";
  items[1] = "It's a pelt of a big grizzly bear";
  items[2] = "window";
  items[3] = "A small, round window. There are metal bars in it. You can see endless plains\n"+
  	       "from it";
  items[4] = "bench";
  items[5] = "An old, badly cracked wooden bench leaning to the wall. It's useless";
 set_not_out(1);
		
  }
