inherit "room/room";
object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/lastimada/lastimada");
    move_object(monster, this_object());
  }





add_exit("ladder", "room16.c");

  short_desc = "In the roof";

  long_desc = "The ladder lead to the roof of the mansion. The view from the roof is\n"+
	      "stunning. There are endless plains in the south and north, and the sea can\n"+
	      "also seen from here. Seagulls scream and glide over the waves crashing\n"+
	      "ashore. Light forest in the east seems to continue to the horizon. Strong\n"+
              "wind blows from the sea making it hard to maintain balance. The ground seems\n"+
              "to be awfully far from here.\n";
		  

  items = allocate(2);
  items[0] = "seagulls";
  items[1] = "Some seagulls screaming and gliding over the sea";
  
  
  }