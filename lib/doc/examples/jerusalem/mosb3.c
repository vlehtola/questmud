inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/salesman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/mosc3");
  add_exit("west","wizards/nalle/jerusalem/mosb2");
  add_exit("south","wizards/nalle/jerusalem/mosa3");
  short_desc = "Eastern part of the Moslem quarter";
  long_desc =
"This is the eastern part of the Moslem quarter of Jerusalem.\n" +
"A large mosque seems to be located to your north and the center\n" +
"of the quarter to your west. Most of the people here seem to be\n" +
"on their way to one of those places, or then just returning to\n"+
"their humble homes here. You notice the lid that leads to the \n"+
"that could possibly be opened.\n";
}

init() {
    ::init();
   add_action("map", "map");
   add_action("open", "open");
}

open(str) {
  if(str == "lid") {
  say(this_player()->query_name()+" enters the sewers.\n");
  write("You open the lid and enter the sewers.\n");
  move_object(this_player(), "/wizards/nalle/jerusalem/sewg2.c");
  say(this_player()->query_name()+" arrives into the sewers by a passage up.\n");
  return 1;
  }
    return 1;
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/mmap");
   return 1;
}
