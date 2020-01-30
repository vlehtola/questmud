inherit "room/room";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gpeon.c");
move_object(monster, this_object());
}
add_exit("southwest","/wizards/terror/goblin/roomit/g17.c");
add_exit("west","/wizards/terror/goblin/roomit/g23.c");
short_desc = "A dark forest";
long_desc = "As you enter this room you see some rocks and some trees with leaves.\n"+
"On the ground is an old fireplace and you wonder why there isn't any grass.\n"+
"Path leading to west and southwest. You hear some screams from west.\n";
}

