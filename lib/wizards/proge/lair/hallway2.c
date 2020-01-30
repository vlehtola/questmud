inherit "room/room";

object monster1;
object monster2;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/proge/suunnitelmat/lair/easy_blocker_south");
    move_object(monster, this_object());
  }
  if(!monster2) { 
    monster2 = clone_object("/wizards/proge/suunnitelmat/lair/easy_blocker_south");
    move_object(monster2, this_object());
  }

  if(arg) return;
  set_not_out();
  add_exit("out","/wizards/proge/lair/hallway1");
  add_exit("south","/wizards/proge/lair/hallway3");

  short_desc =
"Dark hallway leading deeper underground";

  long_desc = 
"The hallway continues in front of you, taking you deeper and\n"+
"deeper in to the mountain. Entrance behind you is now just a\n"+
"distant spot. Echoes of your footsteps seem to stir up some\n"+
"evil grunts and sounds. There is some dried blood and bones\n"+
"lying on the floor of the hallway. They maybe the only thing\n"+
"left of those adventurers that have tried to explore this deep\n"+
"dungeon.\n";

}
