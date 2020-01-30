inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("south", "/wizards/ahma/castle/rooms/area31a");
  add_exit("east", "/wizards/ahma/castle/rooms/area32");
  short_desc = "In the wine cellar";
  long_desc = "Walking amongst wine barrels and bottle shelves.\n" + 
              "The cellar is a typical wine cellar, full of wine barrels and\n" + 
              "bottle shelves. The harvest seems to have been good this year\n" + 
              "because there is a whole shelf full of bottles marked to be this\n" + 
              "year's vintage. The torches are giving a good illumination to the\n" + 
              "cellar. The warmth of the room is high above the recommended\n" + 
              "temperature for stocking wines. There seems to be some kind of a\n" + 
              "hole dug on the ground to the east.\n";

  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob02");
      move_object(monster01, this_object());
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
      monster01 = clone_object("/wizards/ahma/castle/mob/mob04");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob05");
      move_object(monster02, this_object());
    }
  }
}