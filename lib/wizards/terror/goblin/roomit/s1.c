inherit "room/room";
object monster;
object monster2,monster3,monster4;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/bat.c");
move_object(monster, this_object());
monster2 = clone_object("/wizards/terror/goblin/mokot/bat.c");
move_object(monster2, this_object());
monster3 = clone_object("/wizards/terror/goblin/mokot/bat.c");
move_object(monster3, this_object());
monster4 = clone_object("/wizards/terror/goblin/mokot/lbat.c");
move_object(monster4, this_object());
}
add_exit("up","/wizards/terror/goblin/roomit/g8.c");
short_desc = "A small cave";
long_desc = "You have fallen into and old, dark cave.\n"+
"In the cold darkness you hear the twitterings of some vile creatures.\n";
}

