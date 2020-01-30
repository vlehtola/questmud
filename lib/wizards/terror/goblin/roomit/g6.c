inherit "room/room";
inherit "room/door";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gpeon.c");
move_object(monster, this_object());
}
if(arg) return;
add_exit("east","/wizards/terror/goblin/roomit/g7.c");
add_exit("west","/wizards/terror/goblin/roomit/g5.c");
short_desc = "A dark forest";
long_desc = "You are standing in the middle of forest.\n"+
"You see many pairs of eyes staring at you from behind the trees.\n";
}
