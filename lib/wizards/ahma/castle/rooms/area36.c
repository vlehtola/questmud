inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area37a");
  add_exit("up", "/wizards/ahma/castle/rooms/area35f");
  short_desc = "Beginning of the second floor";
  long_desc = "At the beginning of the second floor of the cavern.\n" + 
              "The red light is luminating somewhat brighter in here as in the upper\n" + 
              "floor. The steam, which is coloured by the red light, is rising from\n" + 
              "the holes on the ground. The source of it must be on a floor below this\n" + 
              "one. Couple of complete stalactites can be spotted from the rising steam\n" + 
              "cloud.\n";
  set_not_out(1);

  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob11");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob12");
      move_object(monster01, this_object());
    }  
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob13");
      move_object(monster01, this_object());
    }
  }
}
