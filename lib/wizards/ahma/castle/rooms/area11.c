inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area12");
  add_exit("south", "/wizards/ahma/castle/rooms/area03");
  short_desc = "In a long hallway";
  long_desc = "On a hallway moving towards the throne room.\n" + 
              "There are no longer so many corpses on the floors, probably because\n" + 
              "the guards were mostly in the entrance area at nights. The partly burnt\n" + 
              "red carpet on the floor is not even close as bloody as in the intersection\n" + 
              "passed. Some light is illuminating from the ceiling, which has partly\n" + 
              "collapsed. On the walls can be seen some paintings which are often seen in\n" + 
              "the castles: The paintings of previous kings and the bravest knights\n";
              
  items = allocate(2);
  items[0] = "painting";
  items[1] = "You decide to take your time and watch some of the old paintings:\n" + 
             "The first two paintings are so badly burnt that you cannot read\n" + 
             "who are painted, though you can recognize a big, bold Z from both\n" + 
             "of the name tags.\n" + 
             "The 3rd painting has survived without damages:\n" + 
             "Ahmud III the king of Sickness and Poverty.\n" + 
             "The picture is shabby and it makes you feel a bit sick.\n\n" + 
             "You stop looking at the pictures";
  
  i = random(3);
  
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
      monster01 = clone_object("/wizards/ahma/castle/mob/mob08");
      move_object(monster01, this_object());
    }
  }
}
