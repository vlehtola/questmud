inherit "room/room";

reset(arg)
{
if(arg) return;

        
short_desc = "Very old forest.";
long_desc = 
"Very old forest with tall trees and bushes everywhere\n" +
"Some animals are here eating grass and undergrowth.\n" +
"Animals don't seem to be scared at all. Breezing\n" +
"wind creates some strange noises.\n";

add_exit("north", "ff2.c");
add_exit("south", "ff16.c");
add_exit("east", "ff10.c");
add_exit("west", "ff8.c");

items = allocate (4);
items[0] = "trees";
items[1] = "These are very old and extremely tall trees.\n";
items[2] = "bushes";
items[3] = "These bushes are some short of berrybushes.\n";
move_object(clone_object("/wizards/yodin/forest/monsters/human.c"), this_object());           

}