inherit "room/room";


object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/raphael");
    move_object(monster, this_object());

}

add_exit("down","/wizards/veron/areat/golem/torni2.c");




  short_desc = "Raphael's chambers";

 
  long_desc = "This is the chamber of Raphael, the master of this mansion. The room looks\n"+
	      "very comfortable and warm. A red fitted carpet covers the whole floor. Some \n"+
	      "bookshelves full of books are placed to the northern wall. Small round \n"+
		"windows in the western and eastern walls let in some daylight. A head-sized \n"+
		"red ball of light floats over a big wooden desk in the middle of the room. \n"+
		"There are also some colorful carpets hanging on the walls. A fluffy sofa \n"+
                "is placed under the window in the western wall.\n";
              
		  
  items = allocate(16);
  items[0] = "carpet";
  items[1] = "A red fitted carpet covering the whole floor. It is nailed to the floor";
  items[2] = "bookshelves";
  items[3] = "Oaken bookshelves placed to the northern part of the room. They're full of dull-looking books";
  items[4] = "books";
  items[5] = "Some dull-looking, weird books of magic. They are written in an unknown language";
  items[6] = "windows";
  items[7] = "Small round windows in the western and eastern walls. The sea can be seen from \n"+
		 "the western window, the eastern window gives a clear view to the endless plains in the east";
  items[8] = "ball";
  items[9] = "A head-sized ball of light floating over the desk. It gives some dim light and warmth to the room";
  items[10] = "desk";
  items[11] = "A big wooden desk in the middle of the room. A red ball of light floats over it. There's nothing on the desk";
  items[12] = "carpets";
  items[13] = "Colorful carpets hanging on the walls";
  items[14] = "sofa";
  items[15] = "A comfortable, fluffy sofa. It is placed under the eastern window";
 
	set_not_out(1);	
  }