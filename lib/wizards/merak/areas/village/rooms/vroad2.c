/* village road 2 */
inherit "room/room";

reset(arg) {

  add_exit("north","/wizards/merak/areas/village/rooms/vgates");
  add_exit("south","/wizards/merak/areas/village/rooms/vroad1");
  short_desc = "A path to the Village of Chori";
  long_desc =
	"You are on a small path leading to the Village of Chori. \n" +
	"To the north you can see the village gates and a bit\n" +
	"further you can see a small market square. To the south \n" +
	"the path leads thru a light forest to the great plains \n" +
	"surrounding the village.\n";

}