inherit "room/room";

reset(arg)
{
if(arg) return;

        
short_desc = "Very old forest.";
long_desc = 
"You are walking in the very old forest. All around\n" +
"you are many tall trees and small bushes. Walking\n" +
"in forest is very difficult because all those bushes\n" +
"and spiky rocks.\n";
add_exit("north", "ff7.c");
add_exit("south", "ff21.c");
add_exit("west", "ff13.c");

items = allocate (4);
items[0] = "trees";
items[1] = "These are very old and extremely tall trees.\n";
items[2] = "bushes";
items[3] = "These bushes are some short of berrybushes.\n";
move_object(clone_object("/wizards/yodin/forest/monsters/bear.c"), this_object());           

}