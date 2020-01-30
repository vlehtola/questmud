inherit "room/room";
object monster, monster1;
int founddoor, opendoor;

reset(arg) {
	if(!monster) {
	monster = clone_object("/wizards/rimber/cave/dweller.c");
	move_object(monster, this_object());
	}
	if(!monster1) {
	monster1 = clone_object("/wizards/rimber/cave/dweller.c");
	move_object(monster1, this_object());
	}
	if(arg) return;
	founddoor = 0;
	opendoor = 0;
	set_light(3);
	short_desc = "Dark and damp cavern";
	long_desc = "You stand in the edge of huge round room.\n"+
                "The room is shaped like a hemisphere, the ceiling is at\n"+
               "its highest in the center of the room. Few rays of light\n"+
            "make narrow pillars from the ceiling to the ground.\n"+
            "Three of the pillars unite in the middle of the room,\n"+
            "making a bigger spot of light on the ground.\n"+
           "Light reveals the sandy ground.\n";
        items = allocate(6);
	items[0] = "spot";
        items[1] = "Some footprints can be seen to lead next to the spot\n"+
   "of light, but then disappearing into the sand.";
	items[2] = "sand";
        items[3] = "A metallic object seems to stick out from the sand.";
        items[4] = "object";
        items[5] = "An unkown metallic object on the ground is covered with dust and sand.";
	add_exit("west", "/wizards/rimber/cave/room5.c");
 set_not_out(1);
}

init() {
        ::init();
        add_action("dust", "dust");
        add_action("open", "open");
        add_action("lift", "lift");
}

dust(str) {
        if(str == "spot") {
          say(this_player()->query_name()+" dusts the ground and reveals a trapdoor which is locked with a hook.\n");
          write("You dust the ground and find a trapdoor which is locked with a hook.\n");
          founddoor = 1;
        return 1;
        }
 else { write("Dust "); }
}

lift(str) {
	if(founddoor == 1 && opendoor == 0) {
	 if(str == "hook") {
	  say(this_player()->query_name()+" lifts the hook from the socket.\n");
	  write("You lift the hook.\n");
	  opendoor = 1;
	  return 1;
	 }
	}
 else { write("Lift "); }
	if(opendoor == 1) {
	 write("The hook is already moved.\n");
	return 1;
	}
}

open(str) {
        if(opendoor == 1 && founddoor == 1) {
	 if(str == "trapdoor") {
	   object momo;
	   momo = clone_object("/wizards/rimber/cave/momo.c");
           say(this_player()->query_name()+" opens the trapdoor and something jumps out from it.\n");
	   write("You open the trapdoor and suddenly something jumps out from it.\n");
           move_object(momo, this_object());
	   opendoor = 2;
         return 1;
         }
        }
 	if(opendoor == 2) {
	 write("The door is already open.\n");
	 return 1;
	}
       if(opendoor == 0 && founddoor == 1) {
      write("Trapdoor is locked with a hook.\n");
      return 1;
       }
        write("Open what?\n");
       return 1;
}
