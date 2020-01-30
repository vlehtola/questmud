inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/moskneel");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/mosquec1");
  add_exit("east","wizards/nalle/jerusalem/mosqueb2");
  add_exit("south","wizards/nalle/jerusalem/mosquea1");
  short_desc = "The west side of the mosque";
  long_desc =
"This part of the mosque seems to be dedicated for prayer.\n" +
"There are not very many people present right now, the time\n" +
"when Moslems pray the most is soon past. There are more\n" +
"people who seem deep in prayer to the north and the\n" +
"northeast. \n";
}

