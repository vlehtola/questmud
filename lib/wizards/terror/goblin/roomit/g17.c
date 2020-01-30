inherit "room/room";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gpeon.c");
move_object(monster, this_object());
}
add_exit("north","/wizards/terror/goblin/roomit/g16.c");
add_exit("west","/wizards/terror/goblin/roomit/g24.c");
add_exit("northeast","/wizards/terror/goblin/roomit/g18.c");
short_desc = "A luke warm fog";
long_desc = "You are standing in luke warm fog.\n"+
"You begin to see some things.\n"+
"As your eyes get accustomed to see easier you discover some path leading northeast.\n";
}

