inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("south", "/wizards/ahma/castle/rooms/area13a");
  add_exit("up", "/wizards/ahma/castle/rooms/area15");
  short_desc = "Hallway leading to stairway";
  long_desc = "Near a stairway leading to upstairs.\n" + 
              "The orange-painted corridor leads from throne room to the second floor\n" + 
              "of the castle, and other way around. A chandelier has fallen down from\n" + 
              "the ceiling and is now lying on the floor by the eastern wall. Castle's\n" + 
              "emblems are hanging on the walls. This part of the castle looks cleaner\n" + 
              "and less destroyed than the lobby-part and throne room of the castle. To\n" + 
              "north is a numerous set of red-carpeted stairs which lead to the second\n" + 
              "floor of the castle where all the bedrooms are situated. To south is the\n" + 
              "throne room.\n";

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
      monster01 = clone_object("/wizards/ahma/castle/mob/mob02");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob09");  
      move_object(monster02, this_object());
    }  
  }
}
