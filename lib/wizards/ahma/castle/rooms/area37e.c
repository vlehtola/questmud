inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("south", "/wizards/ahma/castle/rooms/area37f");
  add_exit("west", "/wizards/ahma/castle/rooms/area37c");
  add_exit("east", "/wizards/ahma/castle/rooms/area37g");
  short_desc = "In the second floor of the cavern";
  long_desc = read_file("/wizards/ahma/castle/sfloordesc");

  set_not_out(1);

  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob12");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob14");
      move_object(monster01, this_object());
    }  
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob11");
      move_object(monster02, this_object());
    }   
  
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob13");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob15");
      move_object(monster02, this_object());
    }
  }
}
