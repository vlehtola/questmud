inherit "room/room";

object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/cotd/mobs/carcass");
    move_object(monster, this_object());
  }

if(arg) return;
add_exit("south","/wizards/veron/areat/cotd/street1.c");
add_exit("north","/wizards/veron/areat/cotd/street3.c");
add_exit("west","/wizards/veron/areat/cotd/bs1.c");
add_exit("east","/wizards/veron/areat/cotd/inn1.c");

  short_desc = "Main street";

  long_desc = "You're standing in the main street of a small and dusty\n"+
              "mining town. The so-called main street is only some ten feet\n"+
	      "wide. The whirling and howling wind blows sand from the plains\n"+
              "making air uncomfortable to breath. The blacksmith seems to live\n"+
	      "in the house to the west. The big building in the east has a large\n"+
	      "sign in its wall reading 'Boulder, bed and breakfast'. A carcass\n"+
	      "of a big animal lies in the ground in front of the inn.\n";
              

  items = allocate(6);
  items[0] = "house";
  items[1] = "A quite large house with broken windows. It looks like a blacksmithy";
  items[2] = "sign";
  items[3] = "The sign reads:'Boulder, bed and breakfast'. Boulder must be the inn's name";
  items[4] = "carcass";
  items[5] = "A partly-eaten and rotten corpse of a horse. It has been leashed to the wall\n"+
	     "and has probably been dead at least for a week";
 	
  }
