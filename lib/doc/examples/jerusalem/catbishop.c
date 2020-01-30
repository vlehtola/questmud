inherit "room/room";

object monk;

reset(arg) {
    if(!monk) {
    monk = clone_object("/wizards/nalle/jerusalem/monsters/monk");
    move_object(monk, this_object());
 } 
  if(arg) return;
  add_exit("down","wizards/nalle/jerusalem/catb7");
  short_desc = "On the top of the stairs";
  long_desc =
"You have arrived to the top of the stairs. There are a few paintings on the\n" +
"walls and a thick carpet has been placed on the floor. There is a monk \n" +
"standing by the door. You wonder if he'd let you in.\n";
}

init() {
    ::init();
   add_action("knock", "knock");
}

knock(str) {
   if(str == "door") {
   if (present("monk", environment(this_player()))) {
  say(this_player()->query_name()+" knocks on the door which is quickly opened by the monk.\n");
  write("You knock on the door and the monk opens it quickly\n");
  add_exit("north","wizards/nalle/jerusalem/catbishop3");
  return 1;
   }
  return 0;
  }
 return 0;
}
