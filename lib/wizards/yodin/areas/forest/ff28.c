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
"You are walking in path that leads to deaper in this old\n" +
"and creepy forest. All around are very tall trees and small \n" +
"bushes. Some animal sounds can be heard from somewhere. Walking\n" +
"in this forest is pretty hard because all the bushes and rocks.\n";

add_exit("northwest", "ff15.c");
add_exit("southeast", "ff27.c");

items = allocate (4);
items[0] = "trees";
items[1] = "These are very old and extremely tall trees.\n";
items[2] = "bushes";
items[3] = "These bushes are some short of berrybushes.\n";

}
