inherit "room/room";

object monster1;
object monster2;
object monster3;
object monster4;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/proge/suunnitelmat/lair/aggro_orc");
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
  if(arg) return;
  set_not_out();
  add_exit("north","/wizards/proge/lair/hallway13");
  add_exit("down","/wizards/proge/lair/hall_1_6");

  short_desc =
    "Underground passage leading down";

  long_desc = 
    "This seems to be a widening in the cave. There is a somekind\n"+
    "of stairway leading downwards. There's a groove for guards\n"+
    "next to the stairway. It is surprisingly clean here, considering\n"+
    "the cave leading here.\n";
}
