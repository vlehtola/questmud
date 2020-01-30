inherit "room/room";

object monster1;
object monster2;
object monster3;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/proge/suunnitelmat/lair/blocker_south");
    move_object(monster, this_object());
  }
  if(!monster2) { 
    monster2 = clone_object("/wizards/proge/suunnitelmat/lair/blocker_south");
    move_object(monster2, this_object());
  }
  if(!monster3) { 
    monster3 = clone_object("/wizards/proge/suunnitelmat/lair/blocker_south");
    move_object(monster, this_object());
  }
  if(arg) return;
  set_not_out();
  add_exit("north","/wizards/proge/lair/hallway11");
  add_exit("south","/wizards/proge/lair/hallway13");

  short_desc =
    "Corridor leading deeper";

  long_desc = 
    "You're standing in corridor, which continues to west and south.\n"+
    "The air stinks of orcs, floor and walls are covered in blood.\n"+
    "On the floor of the corridor is some pieces of wood, probably\n"+
    "from torches. Wailing, screams and evil grunts fill your ears.\n"+
    "There's something deeper in there and you're getting closer.\n";
}
