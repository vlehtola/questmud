inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/drunkmonk");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/catcellar3w");
  add_exit("east","wizards/nalle/jerusalem/catcellar2");
  short_desc = "The wine cellar";
  long_desc =
"Tyrannous oaken barrels surround you as you walk around the\n" +
"cathedrals wine cellar looking around in awe. There seem to\n" +
"be quite a few monks taking a break here. There is a plaque on\n" +
"the wall marked 'Sanctus Humulus Lupulus'.\n";
}
