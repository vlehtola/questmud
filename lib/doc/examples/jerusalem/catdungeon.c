inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/sleepguard");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("up","wizards/nalle/jerusalem/catb1");
  add_exit("down","wizards/nalle/jerusalem/catdungeon2");
  short_desc = "A dark passage down";
  long_desc =
"A dark stairway leading down. You hear nothing but the\n" +
"snoring of the monk left to guard the passage down.\n" +
"The staircase is lit with only one torch, and the light\n" +
"that shines from upstairs.\n";
}
