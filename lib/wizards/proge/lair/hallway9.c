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
  add_exit("east","/wizards/proge/lair/hallway10");
  add_exit("south","/wizards/proge/lair/hallway8");

  short_desc =
    "In the corner of the dark cave";

  long_desc = 
    "In the corner of the cave, which continues to east and south.\n"+
    "The air stinks of orcs, floor and walls are covered in blood.\n"+
    "Walls of this cave look old, and there is some signs of camps\n"+
    "in small grooves.\n";
}
