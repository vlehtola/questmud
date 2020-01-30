inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area45");
  add_exit("south", "/wizards/ahma/castle/rooms/area41");
  short_desc = "On a glowing road";
  long_desc =  "On a glowing road.\n" + 
               "When standing between the steaming geysirs a lot more of this large room\n" + 
               "can be seen. In north the actual ground ends and the road is held in mid-\n" + 
               "air by numerous glowing stony pillars which rise from the bubbling mass\n" + 
               "probably more than 100 feet below you. The geysirs blow their hot air\n" + 
               "towards you. In the north, where the road leads, can be seen a high red\n" + 
               "and black tower. The tower is a shape of a cylinder and it is not very wide,\n" + 
               "but it must have at least seven floors.\n";

  set_not_out(1);

  i = random(3);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob14");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob14");
      move_object(monster02, this_object());
      set_blocker("elemental", "north");
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob15");
      move_object(monster01, this_object());
    }  
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob14");
      move_object(monster02, this_object());
      set_blocker("hunter", "north");
    }
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob16");
      move_object(monster01, this_object());
      set_blocker("master", "north");
    }
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob14");
      move_object(monster01, this_object());
    }
  }
}