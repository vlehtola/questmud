inherit "room/room";
object monster;
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/lismonk");
    move_object(monster, this_object());
  }
if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/catd5");
  add_exit("west","wizards/nalle/jerusalem/catc4");
  short_desc = "The benches on the right";
  long_desc =
"You are in the eastern side of main hall, at the benches that\n" +
"are on the right from the walkway to the altar. A monk is sitting\n" +
"here at the back of the hall, sleeping calmly. A beautiful\n" +
"light shines in through the coloured glass windows.\n";
}

