inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("east", "/wizards/ahma/castle/rooms/area24");
  short_desc = "A dead end";
  long_desc = "In the corridor.\n" + 
              "The marbly corridor continues towards the bathing area.\n" + 
              "It soon becomes clear that the bathing area is off limits due to\n" + 
              "the failed passageway above. All kinds of rubble has fallen down\n" + 
              "from upstairs; Paintings, chairs, silvery furniture, even human body\n" + 
              "parts. The way is totally blocked.\n";

  i = random(5);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster01, this_object());
    }

    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob09");
      move_object(monster02, this_object());
    }
  }
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }

    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob07");
      move_object(monster02, this_object());
    }
  }  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob05");
      move_object(monster01, this_object());
    }
  }  
  if(i == 3) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob10");
      move_object(monster01, this_object());
    }
  }  
  if(i == 4) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob10");
      move_object(monster01, this_object());
    }
  }  
}