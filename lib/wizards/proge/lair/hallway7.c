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
  add_exit("east","/wizards/proge/lair/hallway6");
  add_exit("south","/wizards/proge/lair/hallway8");

  short_desc =
    "In the corner of the dark cave";

  long_desc = 
    "In the corner of the cave, which continues to east and south.\n"+
    "The roof of the corridor is little higher here. The stink of orcs\n"+
    "fills the air, the floor and walls are covered in blood. Seems\n"+
    "like battle took place in here. Noises, which are echoing about,\n"+
    "are getting louder.\n";
}
