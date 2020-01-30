inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/area/monsters/realdarvox.c");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("down","/wizards/nalle/area/monsters/darvguard.c");
  short_desc = "Darvox's Lounge";
  long_desc =
"The dimensions of this room are huge. The ceiling is 20 feet high. There \n" +
"is a long wooden desk in the northern part of the room. Behind it there is\n" +
"a black throne, with a black robed man sitting on it. \n";
}

init() {
    ::init();
   clone_object("/wizards/nalle/area/monsters/darvguard");
   move_object("/wizards/nalle/area/monsters/darvguard", this_object());
}
