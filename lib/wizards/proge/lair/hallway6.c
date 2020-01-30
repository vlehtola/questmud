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
    monster2 = clone_object("/wizards/proge/suunnitelmat/lair/easy_aggro_orc");
    move_object(monster2, this_object());
  }
  if(!monster3) { 
    monster3 = clone_object("/wizards/proge/suunnitelmat/lair/easy_aggro_troll");
    move_object(monster, this_object());
  }
  if(arg) return;
  set_not_out();
  add_exit("south","/wizards/proge/lair/hallway5");
  add_exit("north","/wizards/proge/lair/hallway7");

  short_desc =
    "In the dark cave leading deeper underground";

  long_desc = 
    "You can hear grunts echoing in the long hallway of the cave, leading\n"+
    "in to the mountain. The air is getting thicker, it stinks of death and\n"+
    "orcs and trolls. Nasty scrapes in the walls tell of the battles fought\n"+
    "in the narrow corridor ahead. Some bloody rags are lying dried on the\n"+
    "floor, as if someone would have eaten the meat those clothes once were\n"+
    "covering.\n";
}
