inherit "room/room";
object bear;
reset(arg)
{

if(!bear) {
  bear = clone_object("/wizards/yodin/areas/forest/monsters/bear");
  move_object(bear, this_object());
}
if(arg) return;


short_desc = "Very old forest.";
long_desc =
"This forest is old and somehow creepy. Small animals\n" +
"are eating some grass here. Breezing wind makes you\n" +
"feel very chilly. Some hunters are stalking some animals\n" +
"to catch.\n";
add_exit("north", "ff4.c");
add_exit("south", "ff18.c");
add_exit("east", "ff12.c");
add_exit("west", "ff10.c");

items = allocate (4);
items[0] = "trees";
items[1] = "These are very old and extremely tall trees.\n";
items[2] = "bushes";
items[3] = "These bushes are some short of berrybushes.\n";


}