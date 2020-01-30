inherit "room/room";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gpeon.c");
move_object(monster, this_object());
}
add_exit("east","/wizards/terror/goblin/roomit/g17.c");
add_exit("south","/wizards/terror/goblin/roomit/g21.c");
short_desc = "A light forest";
long_desc = "You see the sun shining through the trees and you can see everything clearly.\n"+
"You see only some bushes grass and some thick trees.\n"+
"There are some animals jumping around and looking at you and wondering what is that.\n";

}
