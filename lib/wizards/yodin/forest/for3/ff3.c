inherit "room/room";

reset(arg)
{
if(arg) return;

        
short_desc = "Very old forest.";
long_desc = 
"This forest is old and somehow creepy. Small animals\n" +
"are eating some grass here. Breezing wind makes you\n" +
"feel very chilly. Some hunters are stalking some animals\n" +
"to catch.\n";
add_exit("east", "ff4.c");
add_exit("west", "ff2.c");
add_exit("south", "ff10.c");

items = allocate (4);
items[0] = "trees";
items[1] = "These are very old and extremely tall trees.\n";
items[2] = "bushes";
items[3] = "These bushes are some short of berrybushes.\n";
move_object(clone_object("/wizards/yodin/forest/monsters/bear.c"), this_object());           

}