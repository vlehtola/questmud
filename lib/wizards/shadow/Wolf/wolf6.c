inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/shadow/Wolf/monsters/icepet");
    move_object(monster, this_object());
}

  if(arg) return;
  add_exit("north","/wizards/shadow/Wolf/wolf7");
  add_exit("south","/wizards/shadow/Wolf/wolf5b");
  short_desc = "In the Valley of the Frozen Wolf.";
  long_desc =
  "You are walking in the valley of the frozen wolf. You spot a temple \n" +
  "just northwest from here. The temple has a huge statue on it's roof \n" +
  "that resembles a wolf. The statues eyes seem to follow you.\n" +
  "There is a deep lake west from you, but even in this freezing weather,\n" +
  "the lake feels warm when touched. You are not far away from the temple \n" +
  "And it seems to be made from solid ice. Even that it is made from ice, \n" +
  "transparent ice, you can't see through. It must be because it shines so\n" +
  "much that it hurts your eyes.\n";
}

