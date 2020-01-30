inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area21");
  add_exit("east", "/wizards/ahma/castle/rooms/area19b");
  short_desc = "End of the passageway";
  long_desc = "End of the passageway.\n" + 
              "The passageway ends into a lightbluish stone wall. On the wall is\n" + 
              "hanging a huge, beautiful emblem of the castle. The floor is covered\n" + 
              "with a nice, soft carpet. Some lit candles are hanging on the wall\n" + 
              "where is also the entrance to the fourth bedroom.\n";
  items = allocate(2);
  items[0] = "emblem";
  items[1] = "The emblem is shaped like five-cornered knight's shield. It has a yellow\n" + 
             "background and a black cross on it. On the foreground is a brown-grayish\n" + 
             "shape of a wolf and three broadswords. There is also some blue and green\n" + 
             "shapes in the bottom of the emblem, but it is not too obvious what they\n" + 
             "are supposed to signify. The whole thing is lined with a white line with\n" + 
             "some shadowing. The emblem is a beautiful and tranquilizing symbol of the\n" + 
             "brotherhood of Lhavorak";

  i = random(5);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob05");
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
      monster01 = clone_object("/wizards/ahma/castle/mob/mob07");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob10");
      move_object(monster02, this_object());
    }  
  }
}
