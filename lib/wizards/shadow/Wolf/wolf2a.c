inherit "room/room";

object monster,monster2;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/shadow/Wolf/monsters/icewoman");
    move_object(monster, this_object());
}  

 if(!monster2) {
    monster2 = clone_object("/wizards/shadow/Wolf/monsters/iceman");
    move_object(monster2, this_object());
}
  if(arg) return;
  add_exit("west","/wizards/shadow/Wolf/wolf2");
  short_desc = "A small cave.";
  long_desc =
"You are in a small but dark cave. even that the ground is covered with\n" +
  "a little snow, you feel warm. The walls are transparent because this\n" +
  "cave has been carved in solid ice. On each shining sides of the room \n" +
  "there are bedlike places made from stone. There is a small fireplace\n" +
  "and some cooking gear in the middle of the room.\n";
}

