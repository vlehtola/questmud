/* market square 3 (center)*/

inherit "room/room";
object monster;

reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/merak/areas/village/mobs/merchant");
    move_object(monster, this_object());
  }
  if(arg) return;

  add_exit("south","/wizards/merak/areas/village/rooms/msquare1");
  add_exit("north","/wizards/merak/areas/village/rooms/msquare5");
  add_exit("east","/wizards/merak/areas/village/rooms/msquare4");
  add_exit("west","/wizards/merak/areas/village/rooms/msquare2");
  short_desc = "Center of the market square";
  long_desc =
	"You are standing in the midle of the market square of Chori \n" +
	"village. Just beside you is an impressive looking stone statue\n" +
	"of a knight wearing a full platemail and wielding a huge two-handed\n" +
	"sword. You notice a small plaque attached to the root of the statue.\n" +
	"Besides the impressive statue, there is very little that would catch\n" +
	"your atention, just very few merchants and beggars trying to make\n" +
	"daily living.\n";
	

}