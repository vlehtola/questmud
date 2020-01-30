inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/mosman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/mosb1");
  add_exit("east","wizards/nalle/jerusalem/mosa2");
  short_desc = "Southwestern part of the Moslem quarter";
  long_desc =
"This is the Southernwestern part of the Moslem quarter of\n" +
"Jerusalem. Many of the houses here are built in round forms\n" +
"and nearly all the doorways are arched. This part of the town\n" +
"seems to be pretty much occupied by small cafes and stores.\n" +
"Some men are spending their time here.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/mmap");
   return 1;
}
