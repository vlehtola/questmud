inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("west", "/wizards/ahma/castle/rooms/area25");
  add_exit("east", "/wizards/ahma/castle/rooms/area13g");
  short_desc = "Beginning of a corridor";
  long_desc = "At the beginning of a corridor.\n" + 
              "This corridor leads to a bathing area of the castle. The bathing\n" + 
              "area is known to be the central area for other kinds of pleasures,\n" + 
              "too. The red carpet on the floor ends and reveals some kind of a\n" + 
              "marble-tiled entity.\n" + 
              "There is a small sign on the wall.\n";
  items = allocate(2);
  items[0] = "sign";
  items[1] = "The text of the sign is written in red-pink colour and the letters\n" + 
             "are very curving and sugary. The sign says:\n" + 
             "'<-- To the Castle of Pleasure'";

  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob08");
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
