/* market square 2 (west)*/

inherit "room/room";
object monster;

reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/merak/areas/village/mobs/merchant");
    move_object(monster, this_object());
  }
  if(arg) return;

  add_exit("east","/wizards/merak/areas/village/rooms/msquare3");
/*  add_exit("west","/wizards/merak/areas/village/rooms/wroad1"); */
  short_desc = "Western part of the market square";
  long_desc =
	"You are standing on the western part of the market \n" +
	"square of Chori village, in the beginning of Western Chori Road.\n" +
	"The place is pretty empty, only few merchants can be seen around\n" +
	"selling their wares. To the east you see an impressive looking\n" +
	"statue of a knight standing on the middle of the market square.\n";

}