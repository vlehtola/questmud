inherit "room/room";

reset(arg)
{
if(arg) return;

        
short_desc = "Very old forest.";
long_desc = 
long_desc = 
"Very old forest with tall trees and bushes everywhere\n" +
"Some animals are here eating grass and undergrowth.\n" +
"Animals don't seem to be scared at all. Breezing\n" +
"wind creates some strange noises.\n";
add_exit("west", "ff40.c");
add_exit("east", "ff42.c");

items = allocate (4);
items[0] = "trees";
items[1] = "These are very old and extremely tall trees.\n";
items[2] = "bushes";
items[3] = "These bushes are some short of berrybushes.\n";
           

}