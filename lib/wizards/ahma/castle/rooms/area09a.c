inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("down", "/wizards/ahma/castle/rooms/area08");
  add_exit("up", "/wizards/ahma/castle/rooms/area09b");
  short_desc = "At the staircase";
  long_desc = "Climbing up the narrow staircase.\n" + 
              "The narrow, stony staircase leads up to the watch tower. Staircase\n" + 
              "is made of stones attached to each other, but the stairs have been\n" + 
              "grinded into a smooth, almost beautiful, mass. There are no windows\n" + 
              "along the way but torches on the inner wall light up the dark way\n" + 
              "up to the tower.\n";

  i = random(5);
  
 if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob09");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob05");
      move_object(monster02, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob04");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob08");
      move_object(monster02, this_object());
    }
   }  
  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster01, this_object());
    }
  }
}