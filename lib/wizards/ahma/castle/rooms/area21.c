inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area20");
  add_exit("south", "/wizards/ahma/castle/rooms/area22");
  add_exit("east", "/wizards/ahma/castle/rooms/area23");
  short_desc = "On a passageway";
  long_desc = "On a passageway.\n" + 
              "The corridor opens into a spacious passageway, revealing you the throne\n" + 
              "room in the floor below, to the west. On the other side of the throne\n" + 
              "room is the collapsed passageway on front of the royal sleeping chambers.\n" + 
              "King's bedroom door is open and its bright white painting is stained with\n" + 
              "blood. The soft carpet is covering the floor. The railing and the wall are\n" + 
              "painted with calming light blue. The third servants' bedroom in behind\n" + 
              "the door on the eastern wall.\n";

  i = random(5);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob06");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob07");
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