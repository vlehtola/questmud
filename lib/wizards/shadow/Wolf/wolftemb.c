inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/shadow/Wolf/monsters/wolfpriest");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","/wizards/shadow/Wolf/wolftem3");
  short_desc = "In the temple of the Wolf.";
  long_desc =
 "You are inside a huge temple that is carved from solid ice. This room \n" +
  "resembles a bedroom. There is a beautiful bed on one side on the room,\n" +
  "and a big, round table on the middle. This seems to be a room of a\n" +
  "priest of some sort. Maybe a priest of the wolf. \n";
}