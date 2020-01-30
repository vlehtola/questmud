inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("south", "/wizards/ahma/castle/rooms/area20");
  add_exit("west", "/wizards/ahma/castle/rooms/area17");
  add_exit("east", "/wizards/ahma/castle/rooms/area19a");
  short_desc = "In a corridor";
  long_desc = "Walking in a corridor.\n" + 
              "The corridor is quite spacy, the soft carpet is covering the floor\n" + 
              "and walls are painted with calming light blue.\n" + 
              "The first bedroom door is in sight. Unlike the royal bedroom doors\n" + 
              "the doors leading to servants' bedrooms are simply made. They are\n" + 
              "painted in white and only few carvings are seen in them. Some candles\n" + 
              "are lighting up the passageway and some blood drops are on the carpet\n" + 
              "near the door.\n";
  i = random(5);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob07");
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
      monster01 = clone_object("/wizards/ahma/castle/mob/mob08");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster02, this_object());
    }  
  }
}
