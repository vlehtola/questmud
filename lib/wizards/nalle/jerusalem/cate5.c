inherit "room/room";
object monster;
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/lismonk");
    move_object(monster, this_object());
  }
if(arg) return;
  add_exit("south","wizards/nalle/jerusalem/catd5");
  add_exit("west","wizards/nalle/jerusalem/cate4");
  short_desc = "The benches on the right";
  long_desc =
"You are in the eastern side of main hall, at the benches that\n" +
"are on the right from the altar. The priest holding the sermon\n" +
"is to your left from here, and his loud voice seems to interrupt\n" +
"this monk's sleeping.\n";
}

