inherit "room/room";
int i;
object spec, monster01, monster02;

reset(arg) {
  add_exit("up", "/wizards/ahma/castle/rooms/area03");
  add_exit("down", "/wizards/ahma/castle/rooms/area35h");
  short_desc = "In a dark hole";
  long_desc = "In a dark hole.\n" + 
              "The hole is tight and uncomfortable. Seems that the hole has been dug not\n" + 
              "too long ago. The air feels very warm and a bit musty. Passageways are\n" + 
              "leading up and down. The light is shimmering down from the hole in the\n" + 
              "ceiling which leads to the castle lobby. A weak reddish glow shimmers from\n" + 
              "down, where the hole seems to continue.\n";
  
  if(!monster01) {
    monster01 = clone_object("/wizards/ahma/castle/mob/mob07");
    move_object(monster01, this_object());
  }
  if(!monster02) {
    monster02 = clone_object("/wizards/ahma/castle/mob/mob07");
    move_object(monster02, this_object());
  }
/*  if(!spec) {
    spec = clone_object("/wizards/ahma/castle/mob/spec02");
    move_object(spec, this_object());
  }*/
}

init() {
  ::init();
  call_out("checki", 2);

}

checki() { 
  call_other("/wizards/ahma/castle/rooms/area35h", "add_exit", "hole", "/wizards/ahma/castle/rooms/area35i");
  call_other("/wizards/ahma/castle/file1","set_new_value",1);
  tell_room(this_object(), "As you arrive the room, you can spot a small pair of glowing eyes staring at\n" + 
      "you from down, from where the warm air floats in. After a moment, the eyes\n" + 
      "disappear, followed by a set of scooting sounds made by a running creature.\n");
  return 1;
}