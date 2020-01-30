inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/pilgrim");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/mosc2");
  add_exit("south","wizards/nalle/jerusalem/mosb3");
  add_exit("enter","wizards/nalle/jerusalem/mosqueb2");
  short_desc = "Northeastern part of the Moslem quarter";
  long_desc =
"This is the Northeastern part of the Moslem quarter of Jerusalem.\n" +
"There is also an entry to a large mosque, the Dome of the Rock here.\n" +
"It seems quite new and seems to have been built against the northern\n" +
"city walls. It is a box-like building with a domed roof and people are\n"+
"streaming in and out of it.\n";
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

