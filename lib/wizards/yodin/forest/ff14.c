inherit "room/room";

reset(arg)
{
if(arg) return;

        
short_desc = "Very old forest.";
long_desc = 
"You are walking in path that leads to deaper in to this old\n" +
"and greepy forest. All around are very tall trees and small \n" +
"bushes. Some animal sounds can be heard from somewhere. Walking\n" +
"in this forest is pretty hard because of all those bushes and rocks.\n"; 

add_exit("northeast", "ff15.c");
add_exit("south", "ff13.c");

items = allocate (4);
items[0] = "trees";
items[1] = "These are very old and extremely tall trees.\n";
items[2] = "bushes";
items[3] = "These bushes are some short of berrybushes.\n";
move_object(clone_object("/wizards/yodin/forest/monsters/deer.c"), this_object());           
move_object(clone_object("/wizards/yodin/forest/monsters/deer.c"), this_object());
}
