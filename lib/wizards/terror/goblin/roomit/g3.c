inherit "room/room";
inherit "room/door";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gpeon.c");
move_object(monster, this_object());
}
if(arg) return;
add_exit("east","/wizards/terror/goblin/roomit/g2.c");
add_exit("west","/wizards/terror/goblin/roomit/g4.c");
short_desc = "A light forest";
long_desc = "Sunlight streams down through the trees like beams of gold.\n";
}
