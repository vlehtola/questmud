inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("west", "/wizards/ahma/castle/rooms/area29");
  add_exit("east", "/wizards/ahma/castle/rooms/area31a");
  short_desc = "Beginning of the cellar";
  long_desc = "At the end of the staircase and beginning of the cellar.\n" + 
              "The cellar can be seen in whole from here. There are torches on each\n" + 
              "wall which make the dark cellar seem quite illuminated. When you step\n" + 
              "on the last stair of the staircase, lots of small figures can be seen\n" + 
              "to disappear behind the wine barrels and into a strange gaping hole in\n" + 
              "the very last corner of the wine cellar. The air feels as warm as in\n" + 
              "the top of the stairs. It's strange though, because this place is deep\n" +
              "under the castle.\n";

  i = random(5);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob06");
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
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }
  }  

}