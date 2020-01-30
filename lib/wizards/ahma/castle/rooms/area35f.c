inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("south", "/wizards/ahma/castle/rooms/area35e");
  add_exit("west", "/wizards/ahma/castle/rooms/area35g");
  add_exit("hole", "/wizards/ahma/castle/rooms/area36");
  short_desc = "In the first floor of the cavern";
  long_desc = read_file("/wizards/ahma/castle/ffloordesc") + 
              "A hole in the wall seems to be leading downwards.\n";

  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob02");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob09");
      move_object(monster01, this_object());
    }  
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob12");
      move_object(monster01, this_object());
    }
  }
}              
