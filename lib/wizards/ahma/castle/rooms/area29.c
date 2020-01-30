inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("south", "/wizards/ahma/castle/rooms/area28");
  add_exit("east", "/wizards/ahma/castle/rooms/area30");
  short_desc = "In a staircase";
  long_desc = "In a small staircase leading to the wine cellar.\n" + 
              "The old-looking stairs are leading down to east. Few torches on the\n" + 
              "walls show the way in to the deep cellar which is supposedly castle's\n" + 
              "wine cellar. The good aromas from the kitchen do not reach in here, thus\n" + 
              "making the odor a bit musty. The castle kitchen is located in south.\n" + 
              "Lots of quiet footsteps can be heard down from the darkness.\n";

  i = random(6);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster01, this_object());
    }
  }
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob02");
      move_object(monster01, this_object());
    }
  }  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }
  }  
}