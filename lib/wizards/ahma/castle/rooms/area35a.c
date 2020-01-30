inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area35e");
  add_exit("south", "/wizards/ahma/castle/rooms/area35d");
  add_exit("west", "/wizards/ahma/castle/rooms/area34");
  add_exit("east", "/wizards/ahma/castle/rooms/area35b");
  short_desc = "In the first floor of the cavern";
  long_desc = read_file("/wizards/ahma/castle/ffloordesc");

  i = random(3);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob09");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob05");
      move_object(monster01, this_object());
    }  
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob11");
      move_object(monster01, this_object());
    }
  }
}
