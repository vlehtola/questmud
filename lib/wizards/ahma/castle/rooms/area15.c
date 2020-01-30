inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("west", "/wizards/ahma/castle/rooms/area16");
  add_exit("east", "/wizards/ahma/castle/rooms/area17");
  add_exit("down", "/wizards/ahma/castle/rooms/area14");
  short_desc = "An intersection";
  long_desc = "At an intersection.\n" + 
              "The soft, carpeted passage separates in three ways. The stairway down\n" + 
              "is leading back to the throne room, the eastern passage is leading to\n" + 
              "servants' bedrooms and the western passage goes to royal bedrooms.\n" + 
              "There are some more paintings on the walls, but nothing out of ordinary.\n" + 
              "A head of some poor man is lying in the bloodpool by the northern wall.\n";

  i = random(6);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob04");
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
      monster01 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster01, this_object());
    }
  }
}
