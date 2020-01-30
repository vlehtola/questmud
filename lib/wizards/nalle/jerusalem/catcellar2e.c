inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/drunkmonk");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/catcellar3e");
  add_exit("west","wizards/nalle/jerusalem/catcellar2");
  short_desc = "The wine cellar";
  long_desc =
"You are surrounded by large barrels and racks of bottles.\n" +
"The torches on the walls light the room very well and you\n" +
"notice large puddles of wine and broken bottles in the\n" +
"corners of the room.\n";
}
