inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/area2/monsters/boy1");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/nalle/area2/b6");
  add_exit("north","wizards/nalle/area2/hotel2");
  short_desc = "The Phileas Hotel";
  long_desc =
"You enter a fairly dark building, which seems to be\n" +
"called the Phileas Hotel. The floor is covered by \n" +
"a thick eastern rug. There is someone behind the\n" +
"desk and a corridor leads north.\n";
}

