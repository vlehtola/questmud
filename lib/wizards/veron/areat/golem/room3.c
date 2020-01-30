inherit "room/room";


object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/servant");
    move_object(monster, this_object());
  }

add_exit("south","/wizards/veron/areat/golem/room2.c");
add_exit("northwest","/wizards/veron/areat/golem/kellari.c");
add_exit("west","/wizards/veron/areat/golem/room4.c");
add_exit("stairs","/wizards/veron/areat/golem/room7.c");

  short_desc = "Huge hall";

  long_desc = "You've arrived to a huge hall. There's a big staircase leading \n"+
              "upstairs just in front of you. Large decorative windows bring\n"+
              "light to the hall. There are a couple of small gargoyle statues\n"+
 	        "by both sides of the staircase. Small plants grow in bowls all\n"+
		  "around the room.\n";
		  
	        
  items = allocate(4);
  items[0] = "plants";
  items[1] = "Small plants growing in bowls that are placed all around the hall";
  items[2] = "statues";
  items[3] = "These statues are a great piece of handicraft. Even the smallest details can\n"+
             "be noticed in them";
 set_not_out(1);
		
  }
