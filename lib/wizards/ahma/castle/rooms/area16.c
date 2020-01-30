inherit "room/room";
int i, h;
object monster01, spec;

reset(arg) {
  add_exit("east", "/wizards/ahma/castle/rooms/area15");
  short_desc = "A corner of a passageway";
  long_desc = "Heading for the royal bedrooms.\n" + 
              "When arriving to the corner the passageway turns heading to south\n" + 
              "where the bedrooms are. It soon becomes clear that there is no way\n" + 
              "to go there. The passageway has collapsed leaving the bedroom doors\n" + 
              "hanging in the mid-air. The king's bedroom door, with its artistic\n" + 
              "curves and symbols, is open and some bloodmarks have stained its\n" + 
              "bright white painting. It is too late to try to save the royalty.\n";

/*  if(!spec) {
    spec = clone_object("/wizards/ahma/castle/mob/spec06");
    move_object(spec, this_object());
  }*/
  
  i = random(5);
  
  if(i == 0) {
    if(!monster01) {
      if(h<5) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob10b");
      move_object(monster01, this_object());
      h++;
      }
    }
  }

  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster01, this_object());
    }
  }  
  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }
  }
  if(i == 3) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob06");
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

init() {
  ::init();
  add_action("south", "south");
}

south() {
  write("The passageway has collapsed and you cannot continue that way.\n");
  return 1;
}
