inherit "room/room";
inherit "room/door";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gpeon.c");
move_object(monster, this_object());
}
add_exit("southwest","/wizards/terror/goblin/roomit/g12.c");
add_exit("west","/wizards/terror/goblin/roomit/g10.c");
short_desc = "A light forest";
long_desc = "Sunlight streams down through the trees like beams of gold.\n";

}

