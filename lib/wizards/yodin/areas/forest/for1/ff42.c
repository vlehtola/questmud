inherit "room/room";
object human;
reset(arg)
{

if(!human) {
  human = clone_object("/wizards/yodin/areas/forest/monsters/human");
  move_object(human, this_object());
}

if(arg) return;


short_desc = "Very old forest.";
long_desc =
"You are walking in the very old forest. All around\n" +
"you are many tall trees and small bushes. Walking\n" +
"in forest is very difficult because all those bushes\n" +
"and spiky rocks.\n";
add_exit("west", "ff41.c");
add_exit("south", "ff43.c");

items = allocate (4);
items[0] = "trees";
items[1] = "These are very old and extremely tall trees.\n";
items[2] = "bushes";
items[3] = "These bushes are some short of berrybushes.\n";


}