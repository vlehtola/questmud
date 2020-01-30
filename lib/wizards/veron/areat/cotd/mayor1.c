inherit "room/room";
object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/cotd/mobs/carcass");
    move_object(monster, this_object());
  }


if(arg) return;
add_exit("south","/wizards/veron/areat/cotd/cs.c");
add_exit("north","/wizards/veron/areat/cotd/mayor2.c");

 short_desc = "A big mansion";

  long_desc = "A huge mansion towers in front of you. \n"+
              "There's a small garden with plenty of flowers in front of the\n"+
	      "building. The mansion is surrounded by a three-feet high\n"+
	      "stone wall. There's an iron gate in the wall, but it is left\n"+
              "open. A single milk jug is in front of the gate.\n"; 	
set_blocker("citizen", "north");
  set_not_out(1);

  items = allocate(4);
  items[0] = "gate";
  items[1] = "The gate is made of iron and looks durable";
  items[2] = "jug";
  items[3] = "A jug full of solid milk. It's been a long time since the milkman's been here";
		
  }