inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/northern/mobs/karud");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("up","/wizards/walla/northern/rooms/lvl2/stairs_d");
  add_exit("north","sw2");
  short_desc = "At a staircase";
  long_desc =
  long_desc =
"The passage is carved into the stone, and is only about 5 feet high, so you have some\n" +
"difficulty moving here. You feel a cool wind on your face, as if it was ventilaed from\n" +
"somewhere up ahead. From various directions, you can hear sounds of armour clanking, and\n" +
"people shouting, like muffled voices. There is a small stream of water here on the ground.\n";
 
}
