inherit "room/room";
object monster;
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/lismonk");
    move_object(monster, this_object());
  }
if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/catd3");
  add_exit("east","wizards/nalle/jerusalem/catc4");
  short_desc = "The benches on the left";
  long_desc =
"You are in the western side of main hall, at the benches that\n" +
"are on the left from the passage to the altar. A monk is sitting here\n" +
"quietly listening to the monk, and dosing off at regular intervals.\n" +
"The exit from the hall is to your southeast.\n";
}

