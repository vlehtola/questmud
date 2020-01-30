inherit "room/room";

object monster1;
object monster2;
object monster3;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/proge/suunnitelmat/lair/easy_aggro_troll");
    move_object(monster, this_object());
  }
  if(!monster2) { 
    monster2 = clone_object("/wizards/proge/suunnitelmat/lair/easy_aggro_troll");
    move_object(monster2, this_object());
  }
  if(!monster3) { 
    monster3 = clone_object("/wizards/proge/suunnitelmat/lair/easy_aggro_troll");
    move_object(monster, this_object());
  }
  if(arg) return;
  set_not_out();
  add_exit("west","/wizards/proge/lair/hallway10");
  add_exit("south","/wizards/proge/lair/hallway12");

  short_desc =
    "Corner in the corridor";

  long_desc = 
    "In the corner of the cave, which continues to west and south.\n"+
    "The air stinks of orcs, floor and walls are covered in blood.\n"+
    "On the floor of the corridor is some pieces of wood, probably\n"+
    "from torches. Wailing, screams and evil grunts are filling your\n"+
    "ears. There's something deeper in there and your getting closer.\n";
}
