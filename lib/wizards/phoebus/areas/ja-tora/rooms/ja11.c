inherit "room/room";
object monster;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/g_villager_mp");
move_object(monster, this_object());
}

if(arg) return;

add_exit("south","/wizards/phoebus/areas/ja-tora/rooms/ja11a");
add_exit("east","/wizards/phoebus/areas/ja-tora/rooms/ja12");
add_exit("west","/wizards/phoebus/areas/ja-tora/rooms/ja10");

short_desc = "On Ja-Tora lane";
long_desc = "To the west Ja-Tora lane continues back into the village. East of here \n"+
                      "is a shop of somekind, with a small sign on its door. To the south is a \n"+ 
                      "small village house which is being painted. \n";
}
