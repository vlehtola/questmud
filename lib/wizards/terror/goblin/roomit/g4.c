inherit "room/room";
inherit "room/door";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/ghunter.c");
move_object(monster, this_object());
}
add_exit("south","/wizards/terror/goblin/roomit/g5.c");
add_exit("east","/wizards/terror/goblin/roomit/g3.c");
short_desc = "A dark forest";
long_desc = "You are standing in the dark forest.\n"+
"You seel several pairs of eyes behind trees.\n"+
"You can't think in this darkness.\n";
}
