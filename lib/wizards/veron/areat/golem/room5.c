inherit "room/room";

object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/egolem");
    move_object(monster, this_object());
  }

add_exit("north","/wizards/veron/areat/golem/room6.c");
add_exit("ladder","/wizards/veron/areat/golem/room4.c");

  short_desc = "A stinking cellar";

  long_desc = "You've arrived in to a small cellar. It stinks awful here.\n"+
		  "There's no light except a small candle burning on the floor.\n"+
		  "Small boxes full of potatoes are piled up in the corners. \n"+
		  "There's also a small wooden bed in the room. A low door leads\n"+
		  "to the north. A ladder leads up to a hatch in the ceiling. There's\n"+
		  "a fresh looking corpse lying on the ground.\n";
              	 
  items = allocate(6);
  items[0] = "boxes";
  items[1] = "Small boxes with potatoes in them. The potatoes are all rotten";
  items[2] = "bed";
  items[3] = "A basic wooden bed. Doesn't look too comfortable out";
  items[4] = "corpse";
  items[5] = "Corpse of the poor milkman. He hasn't been dead for long";
	set_not_out(1);	
  }
