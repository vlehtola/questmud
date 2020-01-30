inherit "room/room";
object monster;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/g_villager_fs");
move_object(monster, this_object());
}

if(arg) return;

add_exit("west","/wizards/phoebus/areas/ja-tora/rooms/ja7");

short_desc = "Village House";
long_desc = "This small house doesn't have a great lot of value about it. It consists \n"+
                      "of two rooms,with a table, a few chairs, somewhere to wash and a bed. \n";
}
