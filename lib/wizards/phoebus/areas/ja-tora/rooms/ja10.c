inherit "room/room";
object monster;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/g_villager_fs");
move_object(monster, this_object());
}

if(arg) return;

add_exit("east","/wizards/phoebus/areas/ja-tora/rooms/ja11");
add_exit("west","/wizards/phoebus/areas/ja-tora/rooms/ja3");

short_desc = "On Ja-Tora lane";
long_desc = "You stand on Ja-Tora lane, to the west lies the village center, while \n"+
                      "to the east the lane continues on. \n";
}
