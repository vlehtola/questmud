inherit "room/room";
object deer;

reset(arg)
{
if(!deer) {
 deer = clone_object("/wizards/yodin/areas/forest/monsters/deer");
 move_object(deer, this_object());
 }

if(arg) return;


short_desc = "Very old forest.";
long_desc =
"You are walking in the very old forest. All around \n" +
"you are many tall trees and small bushes. Walking \n" +
"in the forest is very difficult because all the bushes \n" +
"and spiky rocks.\n";

add_exit("west", "ff9.c");
add_exit("east", "ff7.c");

items = allocate (4);
items[0] = "trees";
items[1] = "These are very old and extremely tall trees.\n";
items[2] = "bushes";
items[3] = "These bushes are some short of berrybushes.\n";



}
