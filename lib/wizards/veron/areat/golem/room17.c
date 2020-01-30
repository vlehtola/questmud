inherit "room/room";


object monster,monster2;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/guard");
    move_object(monster, this_object());
if(!monster2) { 
    monster2 = clone_object("/wizards/veron/areat/golem/mobs/guard");
    move_object(monster2, this_object());
}

}

add_exit("northwest","/wizards/veron/areat/golem/room15.c");
add_exit("east","/wizards/veron/areat/golem/torni1.c");



  short_desc = "Sleeping quarters";

  long_desc = "This seems to be some kind of a sleeping room for the guards.\n"+
		  "Four beds are placed in the room side by side. A big window gives\n"+
		  "an excellent view to the sea. Daylight comes in from the window,\n"+
              "drawing shadows to the room. Two old armchairs have been left \n"+
		  "rotting to the southeastern corner.\n";
	
              
		  
  items = allocate(8);
  items[0] = "beds";
  items[1] = "Four comfortable-looking wooden beds";
  items[2] = "window";
  items[3] = "The sight from the windows is awesome. Waves crashing to the shore, seagulls\n"+
	       "flying high above it..";
  items[4] = "armchairs";
  items[5] = "Two old and worn armchairs";
  items[6] = "chairs";
  items[7] = "Two old and worn armchairs";

  set_not_out(1);
 
		
  }
