inherit "room/room";
object monster01, monster02, monster03;

reset(arg) {
  add_exit("up", "/wizards/ahma/castle/rooms/area37g");
  add_exit("down", "/wizards/ahma/castle/rooms/area39");
  short_desc = "In a hole";
  long_desc = "In a dark place.\n" + 
              "The hole is full of dirt and crushed stone. It is almost pitch black\n" + 
              "and therefore no details can be seen. Even the red light does not reach\n" + 
              "in this musty rathole. A tunnel leads up and down, to the second and\n" + 
              "third floors of the mystical cavern.\n";

  set_not_out(1);
  
  if(!monster01) {
    monster01 = clone_object("/wizards/ahma/castle/mob/mob07");
    move_object(monster01, this_object());
  }
  if(!monster03) {
    monster03 = clone_object("/wizards/ahma/castle/mob/mob07");
    move_object(monster03, this_object());
  }
  if(!monster02) {
    monster02 = clone_object("/wizards/ahma/castle/mob/mob07");
    move_object(monster02, this_object());
  }
}