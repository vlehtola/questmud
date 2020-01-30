inherit "room/room";
object monster;
object monster2;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/g_baker");
move_object(monster, this_object());
}

if(!monster2) {
monster2 = clone_object("/wizards/phoebus/areas/ja-tora/monsters/g_villager_fb");
move_object(monster2, this_object());
}

if(arg) return;

add_exit("west","/wizards/phoebus/areas/ja-tora/rooms/ja4");

short_desc = "Stokies Bakery";
long_desc = "You stand in a small bakery. Bags of flour and freshly baked bread rest \n"+
                      "on tables and great smell linger in the air, what a smell. Against the west\n"+
                      "wall is a flour covered counter with a menu hung on the wall above it, \n"+
                      "which reads  ' Sorry no sale to public ' \n";
}
