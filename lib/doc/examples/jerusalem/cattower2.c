inherit "room/room";
object monster;
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/towlady");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("down","wizards/nalle/jerusalem/cattower");
  short_desc = "A bell tower";
  long_desc =
"You are in the eastern wing of the cathedral, in a bell tower.\n" +
"There are large openings in the walls, so that the sounds of\n" +
"the bell could resound all around the town. There is obviously a\n" +
"large bell in the middle of the room, and a rope that is used to \n" +
"ring it. It seems there is a damsel in distress here aswell.\n";
}

init() {
  ::init();
  add_action("pull", "pull");
  add_action("climb", "climb");
} 


pull(str) {
  if(str == "rope") {
      write("You ring the bell noisily.\n");
      say(this_player()->query_name()+" rings the bell loudly.\n");
      return 1;
    }
}
climb(str) {
   if(str == "rope") {
   write("You manage to climb up the rope.\n");
    say(this_player()->query_name()+" climbs "+
        "up the rope making the bell ring wildly.\n");
    move_object(this_player(), "/wizards/nalle/jerusalem/cattower3.c");
    say(this_player()->query_name()+" arrives into the room by climbing up the rope.\n");
    return 1;
  } else {
 write("There is no way you would be able to climb up that.\n");
 return 1;
 }
}

