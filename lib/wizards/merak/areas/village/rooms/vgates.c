/* village gates */

inherit "room/room";
object monster;

reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/merak/areas/village/mobs/vguard");
    move_object(monster, this_object());
  }
  if(arg) return;

  add_exit("south","/wizards/merak/areas/village/rooms/vroad2");
  add_exit("north","/wizards/merak/areas/village/rooms/msquare1");
  short_desc = "At the village gates";
  long_desc =
	"You are on a small path leading to the Village of Chori. \n" +
	"To the north you can see the village gates and a small\n" +
	"market square. To the south the path leads thru a light forest\n" +
	"to the great plains surrounding the village.\n";

}