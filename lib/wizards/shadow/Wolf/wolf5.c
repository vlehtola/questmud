inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/shadow/Wolf/monsters/oldman");
    move_object(monster, this_object());
}

  if(arg) return;
  add_exit("east","/wizards/shadow/Wolf/wolf5a");
  add_exit("south","/wizards/shadow/Wolf/wolf4");
  short_desc = "In the Valley of the Frozen Wolf.";
  long_desc =
 "In the valley of the frozen wolf.\n" +
  "You are at an end of a path. The path itself extends south \n" +
  "from here and it seems to go around a huge ice wall. Not much north \n" +
  "from here you spot a temple with an huge wolf statue of its roof.\n" +
  "You get a creeping feeling as you think you noticed that the statues\n" +
  "eyes seem to follow you. There is a deep lake north from here, and\n" +
  "your amazed that the lake isn`t frozen solid. As you touch the water\n" +
  "you notice it infact feels to be warm, But you can`t go north over the \n" +
  "lake as it seems too deep. Looks like you will have to go around.\n";
}

