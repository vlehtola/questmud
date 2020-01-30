inherit "room/room";
object monster01, monster02, monster03;

reset(arg) {
  add_exit("south", "/wizards/ahma/castle/rooms/area31c");
  add_exit("west", "/wizards/ahma/castle/rooms/area31b");
  short_desc = "In a corner of the cellar";
  long_desc = "Walking amongst the wine barrels and bottle shelves.\n" + 
              "The cellar is a typical wine cellar, full of wine barrels and\n" + 
              "bottle shelves. The harvest seems to have been good this year\n" + 
              "because there is a whole shelf full of bottles marked to be this\n" + 
              "year's vintage. The torches are giving a good illumination to the\n" + 
              "cellar and the warmth of the room is high above the recommended\n" + 
              "temperature for stocking wines. There is a huge, gaping hole on the\n" + 
              "ground, and some steam is rising from it. The temperature seems to\n" + 
              "be also rising with every step taken towards the hole.\n";
  items = allocate(2);
  items[0] = "hole";
  items[1] = "Large sized, steaming hole with a strange red glow coming from inside.\n" + 
             "Seems that the creatures have entered the castle this way, not from\n" + 
             "the front entrance, making a perfect back- and sneak attack to the\n" + 
             "castle. The hole seems to be big enough for you to slip in there. Though\n" + 
             "all the dark figures you see in the hole might not like that";

  if(!monster01) {
    monster01 = clone_object("/wizards/ahma/castle/mob/mob07");
    move_object(monster01, this_object());
  }
  if(!monster03) {
    monster03 = clone_object("/wizards/ahma/castle/mob/mob07");
    move_object(monster03, this_object());
  }
  if(!monster02) {
    monster02 = clone_object("/wizards/ahma/castle/mob/mob07");
    move_object(monster02, this_object());
  }


}

init() {
  ::init();
  add_action("enter", "enter");
}


enter(str) {
  if(str == "hole") {
  write("You gather your willpower and enter the reddish hole. The temperature is\n" + 
        "rising at every step taken deeper into the cave underneath the castle.\n");
  this_player()->move_player("hole#/wizards/ahma/castle/rooms/area33.c");
  return 1;
  }
}
