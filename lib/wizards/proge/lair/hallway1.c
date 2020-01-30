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
  add_exit("out","/wizards/proge/lab");
  add_exit("south","/wizards/proge/lair/hallway2");

  short_desc =
"Dark hallway leading deeper underground";

  long_desc = 
"In front of you opens large hallway, which seem to reach\n"+
"deeper and deeper under the ground. The faint light coming\n"+
"behind from the entrance to this seemingly evil cave, slowly\n"+
"fades away ahead. There is awful noises echoing, as if some\n"+
"horrid monsters would be waiting for you ahead.\n";

}
