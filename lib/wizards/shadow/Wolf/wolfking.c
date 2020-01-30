inherit "room/room";

object monster;

reset(arg) {
  if(arg) return;
  if(!monster) {
    monster = clone_object("/wizards/shadow/Wolf/monsters/wolfking");
    move_object(monster, this_object());
  }
  add_exit("out","/wizards/shadow/Wolf/wolf4d");
  short_desc = "In a huge room carved in solid ice.";
  long_desc =
 "You have entered in a GIGANTIC room carved in solid ice. Wolf statues\n" +
  "decorate the room and there are paintings of important looking people.\n" +
  "At The end of the room there is a throne like seat witch is covered with wolf\n" +
  "furs. behind you there are two huge doors, seemingly made from black ice. There is\n" +
  "a big fireplace in the middle of the room and it provides light. It is very warm in\n" +
  "room even that it is carved from ice. Before the throne the is a altar made from\n" +
  "gold. It has bloodstains all over it, some of them seem rather fresh.\n";
}
