inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/moswoman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/mosc1");
  add_exit("east","wizards/nalle/jerusalem/mosb2");
  add_exit("south","wizards/nalle/jerusalem/mosa1");
  add_exit("enter","wizards/nalle/jerusalem/orpa2");
  short_desc = "Western part of the Moslem quarter";
  long_desc =
"This is the Western part of the Moslem quarter of Jerusalem.\n" +
"This part of the Moslem quarter seems to have been created\n" +
"mainly for residential purposes, and therefore you see quite\n" +
"a few women and children in the area. There is also a large\n"+
"arched entrance on the western wall.\n";
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
