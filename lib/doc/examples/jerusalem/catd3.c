inherit "room/room";
object monster;
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/lismonk");
    move_object(monster, this_object());
  }
if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/cate3");
  add_exit("east","wizards/nalle/jerusalem/catd4");
  add_exit("south","wizards/nalle/jerusalem/catc3");
  short_desc = "The benches on the left";
  long_desc =
"You are in the western side of main hall, at the benches that\n" +
"are on the left from the walkway to the altar. A monk is sitting\n" +
"here attempting to listen to what the priest is saying. Despite\n" +
"his efforts fatigue seems to overpower him at times.\n";
}
