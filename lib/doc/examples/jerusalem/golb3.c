inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/beggar");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/golb2");
  add_exit("north","wizards/nalle/jerusalem/gola3");
  short_desc = "The way to Golgatha";
  long_desc =
"A cobblestoned road leading to the south is to your west\n" +
"and it seems a bit like it could a part built to continue\n" +
"the Via Dolorosa. There is definately something interesting\n" +
"to your west, because a big bunch of people are making loud\n"+
"noises and climbing over eachother to see what's happening.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/gmap");
   return 1;
}
