inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/jewwoman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/nalle/jerusalem/jewb3");
  add_exit("west","wizards/nalle/jerusalem/jewc2");
  add_exit("enter","wizards/nalle/jerusalem/store");
  short_desc = "Northeastern part of the Jewish Quarter";
  long_desc =
"You are in the northwestern part of the Jewish quarter of Jerusalem.\n" +
"This part of the town seems like a very nice place to live. The roads\n" +
"are in a good shape and even seem to be regulary cleaned. A\n" +
"shop marked 'The El-Eini Store' catches your eye.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/jmap");
   return 1;
}

