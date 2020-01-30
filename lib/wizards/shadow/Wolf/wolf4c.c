inherit "room/room";

object monster,monster2;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/shadow/Wolf/monsters/iceboy");
    move_object(monster, this_object());
}  

 if(!monster2) {
    monster2 = clone_object("/wizards/shadow/Wolf/monsters/icegirl");
    move_object(monster2, this_object());
}
  if(arg) return;
  add_exit("west","/wizards/shadow/Wolf/wolf4a");
  add_exit("east","/wizards/shadow/Wolf/wolf4d");
 add_exit("north","/wizards/shadow/Wolf/wolf5b");
  short_desc = "A small cave.";
  long_desc =
 "You are in a small but dark cave. The ground is covered with animal\n" +
  "skins and you feel warm. The walls are transparent and they have all\n" +
  "kinds of drawings on them. There are many toy-like things on the ground \n" +
  "and there is various tools for carvings ice here too. There is a small \n" +
  "fireplace in the middle of the room. The cave continues to the west,north\n" +
  "and to the east\n";
}

