inherit "room/room";

object monster1;
object monster2;
object monster3;
object monster4;
object monster5;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/proge/suunnitelmat/lair/aggro_troll");
    move_object(monster, this_object());
  }
  if(!monster2) { 
    monster2 = clone_object("/wizards/proge/suunnitelmat/lair/aggro_troll");
    move_object(monster2, this_object());
  }
  if(!monster3) { 
    monster3 = clone_object("/wizards/proge/suunnitelmat/lair/aggro_orc");
    move_object(monster, this_object());
  }
  if(!monster4) { 
    monster4 = clone_object("/wizards/proge/suunnitelmat/lair/aggro_troll");
    move_object(monster, this_object());
  }
  if(!monster5) { 
    monster5 = clone_object("/wizards/proge/suunnitelmat/lair/aggro_orc");
    move_object(monster, this_object());
  }
  if(arg) return;
  set_not_out();
  add_exit("west","/wizards/proge/lair/hall_1_5");
  add_exit("south","/wizards/proge/lair/hall_2_6");
  add_exit("southwest", "/wizards/proge/lair/hall_2_5");
  add_exit("up", "/wizards/proge/lair/hallway16");

  short_desc =
    "In a hall, bottom of stairway";

  long_desc = 
    "You're standing in a big, lighted hall, full of nasty looking\n"+
    "creatures. There's torches haning on the walls, and on the\n"+
    "other side of the hall you can see somekind of big chair, like\n"+
    "a throne. Hideous creatures swarm everywhere, eating raw flesh\n"+
    "and fighting each other. Screams and wailing is getting louder.\n"+
    "There might be a prison or dungeon of somekind in here. Air\n"+
    "stinks of rotten meat, orcs, trolls and other nasty beasts.\n"+
    "The stone floor is covered in blood, probably result of the\n"+
    "monstrous rituals that the orcs and trolls are having in here.\n";
}
