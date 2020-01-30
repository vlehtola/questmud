inherit "room/room";



object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/cotd/mobs/bsmith");
    move_object(monster, this_object());
  }

add_exit("west","/wizards/veron/areat/cotd/bs2.c");
add_exit("out","/wizards/veron/areat/cotd/street2.c");
add_exit("up","/wizards/veron/areat/cotd/bs3.c");

  short_desc = "Blacksmithy";

  long_desc = "This small room seems to be the place where the blacksmith\n"+
              "sells his goods. The walls are concealed from the floor to the\n"+
	      "ceiling by wide wooden shelves full of wares. A large metallic\n"+
              "desk with an acabus and some random sheets of metal on it\n"+
	      "rules the room. The floor is covered with small nuts and pieces\n"+
	      "of metal. A ladder leading upstairs can be spotted in one of the\n"+
	      "corners. A small wooden door leads out to the street. There's a\n"+
              "window in the eastern wall, and the inn opposite to this building\n"+
              "can be seen from it.\n";
	      
              
  set_not_out(1);
  items = allocate(14);
  items[0] = "shelves";
  items[1] = "The wide wooden shelves conceal the walls and are full of armours, shields and such.\n"+
             "Somehow all the equipment on the shelves seem to have spots of rust in them, like\n"+
             "they'd been here for a long time. It's weird there's no dust on them, though";
  items[2] = "desk";
  items[3] = "A very large desk made completely out of metal. The constructor's must been really\n"+
             "talented blacksmith";
  items[4] = "acabus";
  items[5] = "A small acabus for better calculating the prices of the wares'. It's made of metal\n"+
	     "too, as most of the items in this shop";
  items[6] = "nuts";
  items[7] = "Small nuts covering the floor. They've probably fallen off the shelves";
  items[8] = "ladder";
  items[9] = "A durable-looking ladder in the corner leads to a room upstairs";
  items[10] = "wares";
  items[11] = "Some armours, shields and other metal items the blacksmith usually sell. All the\n"+
              "items have spots of rust in them, like they'd been here for a long time. It's\n"+
              "weird there's no dust on them, though";
  items[12] = "window";
  items[13] = "A small windows meant for ventilating the hot air of the blacksmithy. The inn\n"+
              "in the other side of the street can be seen from it";
 	
  }
