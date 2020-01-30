inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/moskneel");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/nalle/jerusalem/mosquec2");
  add_exit("south","wizards/nalle/jerusalem/mosqueb1");
  short_desc = "The west side of the mosque";
  long_desc =
"You are located to the west from the person conducting\n" +
"the chanting. He is standing inan upright position and facing\n"+
"the people who are praying. Judging by the amount of rugs\n" +
"left unattended, there are much more people here on peak\n" +
"hours. \n";
}

