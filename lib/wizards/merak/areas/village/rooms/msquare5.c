/* market square 5 (north) */

inherit "room/room";
object monster;

reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/merak/areas/village/mobs/merchant");
    move_object(monster, this_object());
  }
  if(arg) return;

/*  add_exit("north","/wizards/merak/areas/village/rooms/nroad"); */
  add_exit("south","/wizards/merak/areas/village/rooms/msquare3");
  short_desc = "Northern part of the market square";
  long_desc =
	"You are standing on the northern part of the market \n" +
	"square of Chori village, in the beginning of Northern Chori Road.\n" +
	"The place is pretty empty, only few merchants can be seen around\n" +
	"selling their wares. To the south you see an impressive looking\n" +
	"statue of a knight standing on the middle of the market square.\n";

}