inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/poorman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/vd7");
  add_exit("east","wizards/nalle/jerusalem/vd9");
  add_exit("north","wizards/nalle/jerusalem/dav1a2");
  add_exit("south","wizards/nalle/jerusalem/gola2");
  short_desc = "Via Dolorosa (8th block)";
  long_desc =
"This is the eighth block of the Via Dolorosa. A beaten dirt track\n" +
"leads south to Golgatha, and an open gate to the north, into\n" +
"David's Tower. There are not very many people here, only a few\n" +
"poor, suspicious looking individuals. The temperature here is very\n" +
"high, but bearable, since the humidity here isn't too bad.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/vd8map");
   return 1;
}
