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
  add_exit("east","/wizards/proge/lair/hallway11");
  add_exit("west","/wizards/proge/lair/hallway9");

  short_desc =
    "In the corner of the dark cave";

  long_desc = 
    "Endless cave continues to east and west. Eerie screams can be\n"+
    "heard eachoing from the east. Pieces of broken weapons are\n"+
    "lying on the ground. You can smell a scent of smoke in the air\n"
    "which stinks of orcs. Floor and walls are covered in blood.\n";
}
