inherit "room/room";

object monster;

reset(arg) {
  if(arg) return;
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/prisoner");
    move_object(monster, this_object());
  }
  add_exit("north","wizards/nalle/jerusalem/catdungeon2");
  short_desc = "The dungeon";
  long_desc =
"This is a dark room which is clearly used as a dungeon.\n" +
"There are piles of hay on the floor, and someone seems\n" +
"to be resting on one of those flea infested beds.\n";
}

