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
"You are in some ancient forest. This forest is very large\n" +
"and some animals are here eating grass. Trees are very long\n" +
"and old. Some hunters are hunting some small animals here.\n" +
"Breezing wind creates some strange noises and it makes you\n" +
"feel very creepy.\n";
add_exit("north", "ff28.c");
add_exit("west", "ff34.c");

items = allocate (4);
items[0] = "trees";
items[1] = "These are very old and extremely tall trees.\n";
items[2] = "bushes";
items[3] = "These bushes are some short of berrybushes.\n";


}