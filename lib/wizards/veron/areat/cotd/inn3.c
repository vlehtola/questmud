inherit "room/room";
reset(arg) {
if(arg) return;
add_exit("west","/wizards/veron/areat/cotd/inn4.c");
add_exit("east","/wizards/veron/areat/cotd/inn5.c");
add_exit("north","/wizards/veron/areat/cotd/inn6.c");
add_exit("stairs","/wizards/veron/areat/cotd/inn1.c");

  short_desc = "Staircase";

  long_desc = "A small dimly lit room with a huge staircase leading downstairs.\n"+
              "There are three doorways here, one to the left,right and north.\n"+
	      "A rotten and bumped door lies in the middle of the room. A small\n"+
              "and rusty chandelier hangs from the ceiling.\n";
            
                set_not_out(1);

  items = allocate(2);
  items[0] = "door";
  items[1] = "A badly damaged door lying on the floor";
 
 	
  }
