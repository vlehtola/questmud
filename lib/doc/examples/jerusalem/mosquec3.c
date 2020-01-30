inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/moskneel");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/mosquec2");
  add_exit("south","wizards/nalle/jerusalem/mosqueb3");
  short_desc = "The east side of the mosque";
  long_desc =
"The floor here is covered by beautiful rugs, on some of \n" +
"someone is kneeling at the very moment. To your west\n"+
"there is a man facing the people who are praying, it seems\n" +
"he is conducting the chanting. There are some other people\n" +
"praying in the mosque too. \n";
}

