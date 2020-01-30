/* market square 4 (east)*/

inherit "room/room";
object monster;

reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/merak/areas/village/mobs/beggar");
    move_object(monster, this_object());
  }
  if(arg) return;

  add_exit("east","/wizards/merak/areas/village/rooms/eastercr1");
  add_exit("west","/wizards/merak/areas/village/rooms/msquare3");
  short_desc = "Eastern part of the market square";
  long_desc =
	"You are standing on the eastern part of the market\n" +
	"square of Chori village, in the beginning of Eastern Chori Road.\n" +
	"The place is pretty empty, only few merchants can be seen around\n" +
	"selling their wares. To the west you see an impressive looking\n" +
	"statue of a knight standing on the middle of the market square.\n";

}