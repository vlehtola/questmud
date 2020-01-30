inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/shadow/Wolf/monsters/iceboy");
    move_object(monster, this_object());
}

  if(arg) return;
  add_exit("east","/wizards/shadow/Wolf/wolf1");
  add_exit("west","/wizards/shadow/Wolf/wolf1b");
  short_desc = "A small cave.";
  long_desc =
  "You are walking in an area covered with a few inches of snow.\n" +
  "You are in a small but dark cave. Even that the ground is covered with\n" +
  "snow, you feel a little warm. On the snow there is some fur and small\n" +
  "prints. The cave continues to your west, but it gets more darker\n" +
  "in there. To the east is the exit out from the cave.\n";
}
