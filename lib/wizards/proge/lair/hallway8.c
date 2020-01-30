inherit "room/room";

object monster1;
object monster2;
object monster3;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/proge/suunnitelmat/lair/easy_aggro_orc");
    move_object(monster, this_object());
  }
  if(!monster2) { 
    monster2 = clone_object("/wizards/proge/suunnitelmat/lair/easy_aggro_orc");
    move_object(monster2, this_object());
  }
  if(!monster3) { 
    monster3 = clone_object("/wizards/proge/suunnitelmat/lair/easy_aggro_orc");
    move_object(monster, this_object());
  }
  if(arg) return;
  set_not_out();
  add_exit("west","/wizards/proge/lair/hallway7");
  add_exit("north","/wizards/proge/lair/hallway9");

  short_desc =
    "Corridor leading east and west";

  long_desc = 
    "Widening in the cave which continues east and north. Blood and guts cover\n"
    "the floor. Maybe the orcs have eaten here those poor adventurers who\n"+
    "dared to enter this scary cave. It still seems to go on and on, deeper in\n"+
    "to the mountain. Weird noises are echoing in from the walls. There is\n"+
    "something living deeper in here.\n";
}
