inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/moskneel");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/mosquec3");
  add_exit("west","wizards/nalle/jerusalem/mosqueb2");
  add_exit("south","wizards/nalle/jerusalem/mosquea3");
  short_desc = "The east side of the mosque";
  long_desc =
"There are some people chanting moslem prayers here, but\n" +
"as the time when Moslems pray the most is soon past \n"+
"there are not that many people here right now. There are\n" +
"a few men kneeling on rugs and praying to your north\n" +
"and to your northwest. \n";
}

