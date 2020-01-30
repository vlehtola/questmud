inherit "room/room";
int i;
object monster01;
reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area32");
  add_exit("west", "/wizards/ahma/castle/rooms/area31a");
  short_desc = "In the wine cellar";
  long_desc = "Walking in the dusty cellar.\n" + 
              "The cellar is a typical wine cellar, full of wine barrels and\n" + 
              "bottle shelves. The harvest seems to have been good this year\n" + 
              "because there is a whole shelf full of bottles marked to be this\n" + 
              "year's vintage. The torches are giving a good illumination to the\n" + 
              "cellar. The warmth of the room is high above the recommended\n" + 
              "temperature for stocking wines. The chief cook's corpse is staring\n" + 
              "you from the ground with its glazed, dead eyes. There seems to be\n" + 
              "some kind of a hole dug on the ground to the north.\n";

  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob06");
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
      monster01 = clone_object("/wizards/ahma/castle/mob/mob02");
      move_object(monster01, this_object());
    }
  }
}