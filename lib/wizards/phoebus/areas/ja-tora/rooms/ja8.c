inherit "room/room";
object monster;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/g_villager_ms");
move_object(monster, this_object());
}

if(arg) return;

add_exit("north","/wizards/phoebus/areas/ja-tora/rooms/ja13");
add_exit("south","/wizards/phoebus/areas/ja-tora/rooms/ja7");
add_exit("east","/wizards/phoebus/areas/ja-tora/rooms/ja24");
add_exit("west","/wizards/phoebus/areas/ja-tora/rooms/ja9");

short_desc = "Church Lane";
long_desc = "You stand the crossroads of Church lane and Diggers road. To  \n"+
                      "the north you can see an entrance to a graveyard, while to the south   \n"+
                      "Church lane continues on. A long dirt path heads off to the east  \n"+
                      "towards the small mountain range. West of here is a small building, \n"+
                      "very much like a shop of kinds. \n";
}
