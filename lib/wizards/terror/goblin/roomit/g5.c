inherit "room/room";
inherit "room/door";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gpeon.c");
move_object(monster, this_object());
}
if(arg) return;
add_exit("north","/wizards/terror/goblin/roomit/g4.c");
add_exit("east","/wizards/terror/goblin/roomit/g6.c");
short_desc = "Light forest";
long_desc = "Sunlight streams through the trees like beams of gold.\n";
"the ground.\n";
}
