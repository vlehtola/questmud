inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area13a");
  add_exit("south", "/wizards/ahma/castle/rooms/area13g");
  add_exit("east", "/wizards/ahma/castle/rooms/area13e");
  short_desc = "Throne room";
  long_desc = "The throne room.\n" + read_file("/wizards/ahma/castle/thronedesc");

  i = random(8);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob04");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob08");
      move_object(monster01, this_object());
    }
  }  
  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob06");
      move_object(monster01, this_object());
    }
  }

  if(i == 3) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob07");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster02, this_object());
    }
  }

  if(i == 4) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob05");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob06");
      move_object(monster02, this_object());
    }
  }

  if(i == 5) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster02, this_object());
    }
  }
}
