inherit "room/room";
object monster;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/g_guard");
move_object(monster, this_object());
}

if(arg) return;

add_exit("east","/wizards/phoebus/areas/ja-tora/rooms/ja3");
add_exit("west","/wizards/phoebus/areas/ja-tora/rooms/ja1");

short_desc = "On Ja-Tora lane";
long_desc = "You stand on Ja-Tora lane, to the west is the exit of the village and \n"+
                      " to the east lies the central square of Ja-Tora.\n";
}
