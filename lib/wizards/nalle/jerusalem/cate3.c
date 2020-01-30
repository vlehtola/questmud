inherit "room/room";
object monster;
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/lismonk");
    move_object(monster, this_object());
  }
if(arg) return;
  add_exit("south","wizards/nalle/jerusalem/catd3");
  add_exit("east","wizards/nalle/jerusalem/cate4");
  short_desc = "The benches on the left";
  long_desc =
"You are in the western side of main hall, at the benches that\n" +
"are on the left from the altar. A monk is sitting here listening\n" +
"to the priest's sermons.\n";
}

