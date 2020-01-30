inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("up", "/wizards/ahma/castle/rooms/area32");
  add_exit("down", "/wizards/ahma/castle/rooms/area34");
  short_desc = "In a hole";
  long_desc = "A small tunnel leading up and down.\n" + 
              "The hole seems to be quite hastily dug. The walls crumble easily\n" + 
              "when touched and the dirt falls down towards the red light which\n" + 
              "is shimmering from down. The air is somewhat heavy to breath and\n" + 
              "it feels very warm, though the tunnel is below ground level.\n";

  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob04");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob10");
      move_object(monster01, this_object());
    }  
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob09");
      move_object(monster01, this_object());
    }
  }
}
