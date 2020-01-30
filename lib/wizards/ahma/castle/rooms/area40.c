inherit "room/room";
int i;
object maggot01, maggot02, monster01;

reset(arg) {
  add_exit("west", "/wizards/ahma/castle/rooms/area41");
  add_exit("east", "/wizards/ahma/castle/rooms/area39");
  short_desc = "Climbing at a small hill";
  long_desc =  "Climbing at a small hill.\n" + 
               "The hillside is untouched, making the advancing quite hard. There\n" + 
               "are some gaping openings where more bright red light is entering the\n" + 
               "room. There are also some radiating, and normal, stones sticking out\n" + 
               "of the ground, dramatically rising the possibility of falling down\n" + 
               "on one of them and breaking your skull. In spite the danger, the hill\n" + 
               "is a work of art with its chaotical symmetry and soothing bright stones.\n";

  set_not_out(1);
  
  if(!maggot01) {
      maggot01 = clone_object("/wizards/ahma/castle/mob/mob07b");
      move_object(maggot01, this_object());
    }
  if(!maggot02) {
      maggot02 = clone_object("/wizards/ahma/castle/mob/mob07b");
      move_object(maggot02, this_object());
    }

i = random(3);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob14");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob15");
      move_object(monster01, this_object());
      set_blocker("hunter", "west");
    }  
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob16");
      move_object(monster01, this_object());
      set_blocker("master", "west");
    }
  }
}