inherit "room/room";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gpeon.c");
move_object(monster, this_object());
}
add_exit("northeast","/wizards/terror/goblin/roomit/g11.c");
add_exit("south","/wizards/terror/goblin/roomit/g13.c");
short_desc = "A luke warm fog";
long_desc = "You are standing in luke warm fog.\n"+
"You begin to see some things.\n"+
"As your eyes get accustomed to see easier you discover some path leading northeast.\n";
}
