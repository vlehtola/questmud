inherit "room/room";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gguard.c");
move_object(monster, this_object());
}
add_exit("east","/wizards/terror/goblin/roomit/lab2.c");
add_exit("leave","/wizards/terror/goblin/roomit/g23.c");
short_desc = "A path behind bushes";
long_desc = "You have find the path leading to goblin laboratory.\n"+
"Be careful it can be dangerous in there.\n";
}

