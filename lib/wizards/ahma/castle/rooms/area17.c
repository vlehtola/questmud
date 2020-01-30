inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("west", "/wizards/ahma/castle/rooms/area15");
  add_exit("east", "/wizards/ahma/castle/rooms/area18");
  short_desc = "In a corridor";
  long_desc = "Heading for the servants' bedrooms.\n" + 
              "The corridor is quite spacy, the soft carpet is covering the floor\n" + 
              "and walls are painted with calming light blue. Few candles still\n" + 
              "light the corridor. Some bloodstains soil the carpet, but in whole,\n" +  
              "the signs of battle are decreasing every step when closing to the\n" + 
              "bedrooms. Only one painting is hanging on the wall.\n";
  items = allocate(2);
  items[0] = "painting";
  items[1] = "In the painting there is a picture of this castle. It is Fall and\n" + 
             "the trees around the castle are beautifully coloured with different\n" + 
             "shades of yellow, red and brown. Some peasants seem to be harvesting\n" + 
             "apples from the apple trees from the castle orchard. And ox is\n" + 
             "pulling a wagon full of hay through the castle gate. The hays are\n" + 
             "probably for feeding the chickens and cows over the wintertime. The\n" + 
             "sky in the picture is bright blue with no clouds in it.\n" + 
             "When comparing that picture to the state in which the castle is now,\n" + 
             "it is just like a dream";

  i = random(6);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob08");
      move_object(monster01, this_object());
    }
  }  
  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob04");
      move_object(monster01, this_object());
    }
  }
}
