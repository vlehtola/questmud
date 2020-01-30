inherit "room/room";

object monster1;
object monster2;
object monster3;
object monster4;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/proge/suunnitelmat/lair/easy_blocker_east");
    move_object(monster, this_object());
  }
  if(!monster2) { 
    monster2 = clone_object("/wizards/proge/suunnitelmat/lair/easy_blocker_east");
    move_object(monster2, this_object());
  }
  if(!monster3) {
    monster3 = clone_object("/wizards/proge/suunnitelmat/lair/easy_blocker_west");
    move_object(monster2, this_object());
  }
  if(!monster4) {
    monster4 = clone_object("/wizards/proge/suunnitelmat/lair/easy_blocker_west");
    move_object(monster2, this_object());
  }
  if(arg) return;
  set_not_out();
  add_exit("west","/wizards/proge/lair/hallway3");
  add_exit("east","/wizards/proge/lair/hallway5");

  short_desc =
    "Deep in dark hallway leading underground";

  long_desc = 
    "In the narrow part of hallway, which continues to east and west\n"+
    "The cave seems to get a bit wider to the west. Looks like the\n"+
    "hallway turns back to north ahead. There is blood spilled in this\n"+
    "place, and there is a stink of orcs in the air.\n";

}
