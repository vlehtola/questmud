inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area31b");
  add_exit("west", "/wizards/ahma/castle/rooms/area30");
  add_exit("east", "/wizards/ahma/castle/rooms/area31c");
  short_desc = "In the wine cellar";
  long_desc = "Walking in the dusty cellar.\n" + 
              "The cellar is a typical wine cellar, full of wine barrels and\n" + 
              "bottle shelves. The harvest seems to have been good this year\n" + 
              "because there is a whole shelf full of bottles marked to be this\n" + 
              "year's vintage. The torches are giving a good illumination to the\n" + 
              "cellar and the warmth of the room is high above the recommended\n" + 
              "temperature for stocking wines.\n";

  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob05");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob10");
      move_object(monster01, this_object());
    }  
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob07");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob08");
      move_object(monster02, this_object());
    }
  }
}