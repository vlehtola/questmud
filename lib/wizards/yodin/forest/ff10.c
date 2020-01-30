inherit "room/room";

reset(arg)
{
if(arg) return;

        
short_desc = "Very old forest.";
long_desc = 
"You are walking in huge forest. All around you are very long \n" +
"trees and small bushes surrounding this path. Walking is very \n" + 
"difficult because all those bushes and spiky rocks. Wind makes \n" + 
"some strange noises.\n";

add_exit("east", "ff9.c");
add_exit("west", "ff11.c");

items = allocate (4);
items[0] = "trees";
items[1] = "These are very old and extremely tall trees.\n";
items[2] = "bushes";
items[3] = "These bushes are some short of berrybushes.\n";
move_object(clone_object("/wizards/yodin/forest/monsters/deer.c"), this_object());           
move_object(clone_object("/wizards/yodin/forest/monsters/deer.c"), this_object());
}
