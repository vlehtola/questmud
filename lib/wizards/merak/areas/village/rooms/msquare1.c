/* market square 1 (south)*/

inherit "room/room";

reset(arg) {
  add_exit("south","/wizards/merak/areas/village/rooms/vgates");
  add_exit("north","/wizards/merak/areas/village/rooms/msquare3");
  short_desc = "Southern part of the market square";
  long_desc =
	"You are standing on the southern part of the market \n" +
	"square of Chori village. The place is pretty empty,\n" +
	"only few merchants can be seen around selling their wares.\n" +
	"To the east you see an impressive looking statue of a knight\n" +
	"standing on the middle of the market square, while to the\n"+
	"south you can see the village gates.\n";
}