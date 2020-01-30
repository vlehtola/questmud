inherit "room/room";

object monster;

reset(arg) {

  if(arg) return; /* added by Celtron */

  monster = clone_object("/wizards/shadow/Wolf/monsters/mastcerem");
  move_object(monster, this_object());
  add_exit("passage","/wizards/shadow/Wolf/wolftem");
  short_desc = "In the temple, under the statue.";
  long_desc =
  "You are in the temple of the Wolf, in a room you got to by a concealed \n" +
  "passage. The room is dark, and the furniture indicates that the room  \n" +
  "is used to perform sacrifices to the wolf gods. A robed individual stands \n" +
  "before a blood covered altar.\n";
}

