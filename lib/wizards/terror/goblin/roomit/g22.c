inherit "room/room";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gpeon.c");
move_object(monster, this_object());
}
add_exit("north","/wizards/terror/goblin/roomit/g23.c");
add_exit("east","/wizards/terror/goblin/roomit/g21.c");
short_desc = "A light forest";
long_desc = "You see light coming from sun and you can see a small path leading north.\n"+
"You can see everything clearly and you see next to the tree some small anthill.\n";

}
