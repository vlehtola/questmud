inherit "room/room";
int i;
object monster01, monster02, monster03;

reset(arg) {
  add_exit("west", "/wizards/ahma/castle/rooms/area06a");
  add_exit("east", "/wizards/ahma/castle/rooms/area06c");
  short_desc = "In a corridor";
  long_desc = "The narrow corridor is made of grayish stones.\n" + 
              "The stones have been piled up and attached to each other firmly, thus\n" + 
              "making the walls really hard to destroy by any invasion attempt. Some\n" + 
              "stains of blood can be seen on the floor. The corridor leads on.\n";
  i = random(3);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob07");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob07");
      move_object(monster02, this_object());
    }
    if(!monster03) {
      monster03 = clone_object("/wizards/ahma/castle/mob/mob07");
      move_object(monster03, this_object());
    }
  }  
  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob06");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob06");
      move_object(monster02, this_object());
    }
  }  
}
