inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/northern/mobs/ishmal");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","sw3");
  add_exit("north","sw1");
  short_desc = "A passage, carved into the stone";
  long_desc =
  long_desc =
"The passage is carved into the stone, and is only about 5 feet high, so you have some\n" +
"difficulty moving here. You feel a cool wind on your face, as if it was ventilaed from\n" +
"somewhere up ahead. From various directions, you can hear sounds of armour clanking, and\n" +
"people shouting, like muffled voices. There is a small stream of water here on the ground.\n";
 
}
