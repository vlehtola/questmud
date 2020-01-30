inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("west", "/wizards/ahma/castle/rooms/area03");
  add_exit("east", "/wizards/ahma/castle/rooms/area06a");
  short_desc = "Hallway turning into a corridor";
  long_desc = "When closing in to the guarding post and the watch tower the hallway\n" + 
              "turns just to a mere corridor. The red carpet, which was covering the\n" + 
              "floor ends, revealing a crude, stony floor. The further you continue,\n" + 
              "the dimmer the corridor gets. The invaders have taken control of the\n" + 
              "post and slain the guards. When reaching the post, the sight will not\n" + 
              "be a nice one.\n";
  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob05");
      move_object(monster01, this_object());
    }
  }
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }

    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob04");
      move_object(monster02, this_object());
    }
  }  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob02");
      move_object(monster01, this_object());
    }

    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob06");
      move_object(monster02, this_object());
    }
  }  
}
