inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("southwest", "/wizards/ahma/castle/rooms/area43");
  add_exit("east", "/wizards/ahma/castle/rooms/area41");
  short_desc = "On a glowing road";
  long_desc =  "On a glowing road.\n" + 
               "The stones on and under this road are radiating a gentle red glow.\n" + 
               "The glow seems to pulsate a little. A squall of warm, sulphurous wind\n" + 
               "blows in from the north when the geysir releases its steamy charge\n" + 
               "with a long sigh in which can be heard some respectable pride. The\n" + 
               "dripstones above are dripping some yellowish water down on the ground.\n" + 
               "The road leads to southwest and east.\n";

  set_not_out(1);

i = random(3);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob16");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob15");
      move_object(monster01, this_object());
    }  
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob15");
      move_object(monster01, this_object());
    }
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob15");
      move_object(monster01, this_object());
    }
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob14");
      move_object(monster01, this_object());
    }
  }
}