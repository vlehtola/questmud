inherit "room/room";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/ghunter.c");
move_object(monster, this_object());
}
add_exit("north","/wizards/terror/goblin/roomit/g24.c");
add_exit("west","/wizards/terror/goblin/roomit/g22.c");
short_desc = "A light forest";
long_desc = "You see the sun shining through the trees and you see everything clearly.\n"+
"You see only some bushes grass and some thick trees.\n"+
"There are some animals jumping around and looking at you and wondering what is that.\n";

}
