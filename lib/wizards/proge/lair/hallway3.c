inherit "room/room";

object monster1;
object monster2;
object monster3;
object monster4;

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
    move_object(monster2, this_object());
  }
  if(!monster4) {
    monster4 = clone_object("/wizards/proge/suunnitelmat/lair/easy_aggro_orc");
    move_object(monster2, this_object());
  }
  if(arg) return;
  set_not_out();
  add_exit("north","/wizards/proge/lair/hallway2");
  add_exit("east","/wizards/proge/lair/hallway4");

  short_desc =
    "Deep in dark hallway leading underground";

  long_desc = 
    "In the corner of the hallway, which continues to the east,\n"+
    "deeper and deeper under ground. The cave seems to get a bit\n"+
    "more narrow ahead. In the north, you can still faintly see the\n"+
    "light coming in.\n";

}
