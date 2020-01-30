inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("west", "/wizards/ahma/castle/rooms/area35h");
  add_exit("east", "/wizards/ahma/castle/rooms/area35f");
  short_desc = "In the first floor of the cavern";
  long_desc = read_file("/wizards/ahma/castle/ffloordesc");

  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob05");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob12");
      move_object(monster01, this_object());
    }  
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob09");
      move_object(monster02, this_object());
    }   
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob06");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob09");
      move_object(monster02, this_object());
    }  
  }
}
