inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/drunkmonk");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/nalle/jerusalem/catcellar2e");
  add_exit("west","wizards/nalle/jerusalem/catcellar3");
  short_desc = "The wine cellar";
  long_desc =
"You are surrounded by large barrels and racks of bottles.\n" +
"There is a very large lidless barrel in the middle of the room.\n" +
"Curious as you are, you try to look in and see what it contains\n" +
"but you cannot, because it is too hig. The only way to see what\n" +
"it holds within would most probably be to climb up into it, which\n" +
"you might just be able to do. The torches on the walls light the\n" +
"room very well and you notice large puddles of wine and broken\n" + 
"bottles in the corners of the room.\n";
}

init() {
    ::init();
   add_action("climb", "climb");
}

climb(str) {
  if(str == "barrel") {
  say(this_player()->query_name()+" climbs up into the barrel. Yikesbump.\n");
  write("You climb up into the barrel, as it has no bottom, you fall down into some other room.\n");
  move_object(this_player(), "/wizards/nalle/jerusalem/sewc1.c");
  return 1;
  }
    return 1;
}



