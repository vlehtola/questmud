inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("up", "/wizards/ahma/castle/rooms/area33");
  add_exit("east", "/wizards/ahma/castle/rooms/area35a");
  short_desc = "Entrance to the cavern";
  long_desc = "At the beginning of a huge cavern.\n" + 
              "A large subterranean cavern opens before your eyes. The room is pretty high,\n" + 
              "more than fifteen feet, and spacious in every way. The source of the strange\n" + 
              "red light is somewhere in the floors below this one, but the light shimmers\n" + 
              "from small holes which are situated randomly on the ground. The dirt, which\n" + 
              "was produced when the hole into the castle was dug, is found near the entrance\n" + 
              "to this cavern. A thin, white steam is rising from the holes on the ground and\n" + 
              "the temperature is higher than it would be on the hottest summer day in the\n" + 
              "plains of Deleria.\n";

  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob09");
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
