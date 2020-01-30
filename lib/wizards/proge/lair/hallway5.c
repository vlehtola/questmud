inherit "room/room";

object monster1;
object monster2;
object monster3;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/proge/suunnitelmat/lair/easy_orc");
    move_object(monster, this_object());
  }
  if(!monster2) { 
    monster2 = clone_object("/wizards/proge/suunnitelmat/lair/easy_orc");
    move_object(monster2, this_object());
  }
  if(!monster3) { 
    monster3 = clone_object("/wizards/proge/suunnitelmat/lair/easy_orc");
    move_object(monster, this_object());
  }
  if(arg) return;
  set_not_out();
  add_exit("west","/wizards/proge/lair/hallway4");
  add_exit("north","/wizards/proge/lair/hallway6");

  short_desc =
    "In the corner of the dark cave";

  long_desc = 
    "In the corner of the cave, which continues to west and north.\n"+
    "You can see the it getting little wider in north. The stink of orcs\n"+
    "fills the air, the floor and walls are covered in blood. This seems\n"+
    "like a place of massacre. Noises, which are echoing about, are\n"+
    "getting louder. Maybe it would be wise to turn back.\n";
}
