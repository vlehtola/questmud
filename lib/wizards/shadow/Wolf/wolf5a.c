inherit "room/room";

object monster,monster2;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/shadow/Wolf/monsters/icegirl");
    move_object(monster, this_object());
}

 if(!monster2) {
    monster2 = clone_object("/wizards/shadow/Wolf/monsters/icepet");
    move_object(monster2, this_object());
}
  if(arg) return;
  add_exit("west","/wizards/shadow/Wolf/wolf5");
  add_exit("east","/wizards/shadow/Wolf/wolf5b");
  short_desc = "Valley of the Frozen Wolf.";
  long_desc =
  "You are standing in knee height in snow. You stumble in the snow \n" +
  "and almost lose balance and you almost fall flat on your face.\n" +
  "directly north from here you spot a temple with an huge wolf statue\n" +
  "decorating its roof. You get a bad feeling as you notice that the statues\n" +
  "eyes seem to follow you. There is a deep lake north from here, and\n" +
  "your amazed that the lake isn`t frozen solid. As you touch the water\n" +
  "you notice it feels infact warm, But you can`t go north over the lake\n" +
  "because it`s too deep. Looks like you will have to go around.\n";
}
