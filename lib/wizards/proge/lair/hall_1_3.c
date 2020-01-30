inherit "room/room";

object monster1;
object monster2;
object monster3;
object monster4;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/proge/suunnitelmat/lair/easy_orc");
    move_object(monster, this_object());
  }
  if(!monster2) { 
    monster2 = clone_object("/wizards/proge/suunnitelmat/lair/easy_orc");
    move_object(monster2, this_object());
  }
  if(!monster3) { 
    monster3 = clone_object("/wizards/proge/suunnitelmat/lair/aggro_orc");
    move_object(monster, this_object());
  }
  if(!monster4) { 
    monster4 = clone_object("/wizards/proge/suunnitelmat/lair/orc");
    move_object(monster, this_object());
  }

  if(arg) return;
  set_not_out();
  add_exit("west","/wizards/proge/lair/hall_1_2");
  add_exit("south","/wizards/proge/lair/hall_2_3");
  add_exit("southwest", "/wizards/proge/lair/hall_2_2");
  add_exit("east", "/wizards/proge/lair/hall_1_4");
  add_exit("southeast", "/wizards/proge/lair/hall_2_4");

  short_desc =
    "Northern side of the hall";

  long_desc = 
    "You're standing in a big, lighted hall, full of nasty looking\n"+
    "creatures. There's torches haning on the walls, and on the\n"+
    "southern side of the hall you can see somekind of big chair, like\n"+
    "a throne. Hideous creatures swarm everywhere, eating raw flesh\n"+
    "and fighting each other. Screams and wailing is getting louder.\n"+
    "There might be a prison or dungeon of somekind in here. Air\n"+
    "stinks of rotten meat, orcs, trolls and other nasty beasts.\n"+
    "The stone floor is covered in blood, probably result of the\n"+
    "monstrous rituals that the orcs and trolls been having in here.\n";
}
