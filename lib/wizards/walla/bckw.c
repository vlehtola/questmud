inherit "room/room";
 
object hani,hani2,hani3;
 
reset(arg) {
  if(!hani) {
    hani = clone_object("/world/objects/trashcan");
    move_object(hani, this_object()); }
  if(!hani2) {
    hani2 = clone_object("/wizards/walla/mariah");
    move_object(hani2, this_object()); }
  if(!hani3) {
    hani3 = clone_object("/wizards/walla/victoria");
    move_object(hani3, this_object()); }
  if(arg) return;
  add_exit("west","wizards/walla/w2");
  add_exit("jericho","wizards/walla/area/cs");
  add_exit("pepe","wizards/walla/peepseye/1");
  add_exit("test","wizards/walla/void");
  add_exit("shaolin","wizards/walla/area2/rooms/entrance");
  add_exit("inn","world/city/inn");
  add_exit("sban","wizards/shadow/shortban");
  add_exit("kitty","wizards/walla/peepseye/kitty/1");
  short_desc = "Walla's Hall of Divine Justice";
  long_desc =
".------.   .    .-----   .-----     .-----. .------ .----- \n" +
"|      |   |    |        |          |     | |       |      \n" +
"|------'   |    `-----.  `-----.    |     | |---    |----  \n" +
"|          |          |        |    |     | |       |      \n" +
"|          |     -----'   -----'    `-----' |       |      \n";
}
