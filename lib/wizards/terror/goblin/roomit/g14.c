inherit "room/room";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gpeon.c");
move_object(monster, this_object());
}
add_exit("west","/wizards/terror/goblin/roomit/g7.c");
add_exit("east","/wizards/terror/goblin/roomit/g13.c");
short_desc = "A forest with a fog";
long_desc = "You are surrounded by a dense fog.\n"+
"You can't see anything clearly but you have feeling that someone is looking at you.\n"+
"You hope that this ugly and wet fog will disappear at once....\n"+
"But that will never become true in this place.\n";
}
