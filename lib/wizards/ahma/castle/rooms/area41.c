inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area44");
  add_exit("west", "/wizards/ahma/castle/rooms/area42");
  add_exit("east", "/wizards/ahma/castle/rooms/area40");
  short_desc = "Underground intersection";
  long_desc =  "At an underground intersection.\n" + 
               "In the ground there are carved some runes, but they are made in language\n" + 
               "you cannot understand. More runes have been carved into a piece of road\n" + 
               "leading to north. The steam from the geysirs is preventing from seeing\n" + 
               "where the road ends. In to the other way the road continues to the west,\n" + 
               "where in a little distance it seems to end into a red wall. In the east\n" + 
               "lays a glowing small hill.\n";

  set_not_out(1);
  
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
      set_blocker("hunter", "north");
    }  
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob14");
      move_object(monster02, this_object());
    }
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob16");
      move_object(monster01, this_object());
      set_blocker("master", "north");
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob14");
      move_object(monster02, this_object());
    }
  }
}