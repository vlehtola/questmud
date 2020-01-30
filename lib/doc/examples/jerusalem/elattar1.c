inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/salesman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/ngate");
  add_exit("south","wizards/nalle/jerusalem/elattar2");
  short_desc = "El Attar (1st block)";
  long_desc =
"This is the first block of the El Attar street. Herod's gate is\n" +
"to your north. The El Attar road continues south. You notice a\n" +
"a lid leading to the sewers here. It could probably be opened and\n" +
"used as an entry to the 'Cloaca Maxima'. There are a few salesmen\n" +
"and merchants traveling in and out of the city by the northern\n" +
"gate of Jerusalem, also known as Herod's gate.\n";
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
  move_object(this_player(), "/wizards/nalle/jerusalem/sewerunderea1.c");
  say(this_player()->query_name()+" arrives into the sewers from the El Attar street.\n");
  return 1;
  }
    return 1;
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/elattar1map");
   return 1;
}

