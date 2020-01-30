inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/beggar");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/elattar3");
  add_exit("south","wizards/nalle/jerusalem/sgate");
  short_desc = "El Attar (4th block)";
  long_desc =
"This is the 4th block of the El Attar road, just north from\n" +
"the Zion gate, which is the southern gate of Jerusalem.\n" + 
"You see some modest looking Armenian people walking \n" +
"here and a lid that could be part of the local sewer system\n" +
"that the Duranghomians have built. \n";
}

init() {
    ::init();
   add_action("map", "map");
   add_action("open", "open");
}

open(str) {
  if(str == "lid") {
  say(this_player()->query_name()+" lifts a sewer lid and quickly jumps in.\n");
  write("You open the lid of the sewer and quickly jump down.\n");
  move_object(this_player(), "/wizards/nalle/jerusalem/sewe6.c");
  say(this_player()->query_name()+" arrives from an entry to the sewers.\n");
  return 1;
  }
    return 1;
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/elattar4map");
   return 1;
}

