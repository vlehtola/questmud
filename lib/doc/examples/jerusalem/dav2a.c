inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/davguard1");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("out","wizards/nalle/jerusalem/dav1c2");
  add_exit("south","wizards/nalle/jerusalem/dav2b");
  short_desc = " Inside David's Tower";
  long_desc =
"You have entered a large room, filled with satin, marble\n" +
"and gold. The air here is cooler than outside, and quite\n" +
"your surroundings are therefore quite pleasant indeed.\n" +
"A guard stands infront of an ascending passage south.\n";
}

