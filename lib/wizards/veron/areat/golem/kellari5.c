inherit "room/room";


object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/desen");
    move_object(monster, this_object());
  }

add_exit("up","/wizards/veron/areat/golem/kellari4.c");

  short_desc = "A small room";

  long_desc = "A small laboratory. Everything is shining clean here.\n"+
              "A cauldron with some green liquid bubbles on an oven in\n"+
              "the eastern corner. Small racks full of test tubes are \n"+
 		  "placed on a metal table in the middle of the room. Spiral\n"+
		  "stairs lead upwards here.\n";
  items = allocate(6);
  items[0] = "cauldron";
  items[1] = "A large cauldron full of weird-looking bubbling liquid";
  items[2] = "racks";
  items[3] = "Small metallic racks full of test tubes. Most of the tubes are empty";
  items[4] = "tubes";
  items[5] = "Small test tubes. Most of the tubes are empty, some have various liquids inside";

 set_not_out(1);
		
  }
