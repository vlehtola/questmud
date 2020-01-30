inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/roman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/gola2");
  add_exit("south","wizards/nalle/jerusalem/golb3");
  short_desc = "The way to Golgatha";
  long_desc =
"A cobblestoned road leading to the south is to your west\n" +
"and it seems a bit like it could a part built to continue\n" +
"the Via Dolorosa. Anyway, there must be something happening\n" +
"here, because there are a good number people cheering and\n"+
"booing at the same time, but you cannot quite make out what.\n";
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
