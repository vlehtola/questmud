inherit "room/room";


object monster;
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/servant");
    move_object(monster, this_object());
  }

add_exit("south","/wizards/veron/areat/golem/room7.c");
add_exit("west","/wizards/veron/areat/golem/room13.c");
add_exit("east","/wizards/veron/areat/golem/room15.c");

  short_desc = "Dining hall";

  long_desc = "This is the dining hall of the mansion. A huge dining table\n"+
		  "is placed right in the middle of the room. There are still\n"+
		  "leftovers of today's meal on the table. A huge chandelier is\n"+
		  "hanging over the dining table. A nice smell drifts to the hall\n"+
	        "from the open door in the west end of the hall.\n";

  items = allocate(6);
  items[0] = "table";
  items[1] = "A huge dining table in the middle of the room. There are some\n"+
             "dishes on the table";
  items[2] = "leftovers";
  items[3] = "Some food which was left over from the dinner";
  items[4] = "chandelier";
  items[5] = "A huge chandelier hangs over the dining table. It is made of iron\n"+
             "and probably weighs a lot";
 set_not_out(1);

		
  }