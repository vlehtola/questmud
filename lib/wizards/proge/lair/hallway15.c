inherit "room/room";

object monster1;
object monster2;
object monster3;
object monster4;

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
  if(!monster4) { 
    monster4 = clone_object("/wizards/proge/suunnitelmat/lair/blocker_south");
    move_object(monster, this_object());
  }
  if(arg) return;
  set_not_out();
  add_exit("north","/wizards/proge/lair/hallway14");
  add_exit("south","/wizards/proge/lair/hallway16");

  short_desc =
    "Passage leading south and north";

  long_desc = 
    "Passage continues to south, widening a bit. There is some light\n"+
    "coming from ahead. Awful voices of orcs are getting louder. The\n"+
    "is getting hot. There must be somekind of bigger cave ahead.\n";
}
