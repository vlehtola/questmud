inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/pilgrim");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/nalle/jerusalem/chrc3");
  add_exit("south","wizards/nalle/jerusalem/chrb2");
  add_exit("west","wizards/nalle/jerusalem/chrc1");
  short_desc = "Northern part of the Christian quarter";
  long_desc =
"This is the northern part of the Christian quarter of the city of\n" +
"Jerusalem. There is a small cathedral to your south, and the rear \n" +
"part of it is very well visible to you from where you are standing.\n" +
"It seems there is a small funeral area to your west, residences to\n" +
"your east and of course the cathedral to your south.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/cmap");
   return 1;
}

