inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/shadow/Wolf/monsters/iceboy");
    move_object(monster, this_object());
}

  if(arg) return;
  add_exit("west","/wizards/shadow/Wolf/wolf3a");
  add_exit("south","/wizards/shadow/Wolf/wolf2");
  short_desc = "In the Valley of the Frozen Wolf.";
  long_desc =
  "You are vandering in the valley of the frozen wolf.\n" +
  "In front of you there is a sort of ice wall that blocks you from  \n" +
  "wandering north. But through it, you can see a huge temple with a.\n" +
  "wolf resembling statue on top of it. It is useless to try and go\n" +
  "through the wall, but you maybe able to go around it \n";
}

