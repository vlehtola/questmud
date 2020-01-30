inherit "room/room";
inherit "room/door";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gpeon.c");
move_object(monster, this_object());
}
if(arg) return;
add_exit("west","/wizards/terror/goblin/roomit/g2.c");
add_exit("east","/wizards/terror/goblin/roomit/g11.c");
short_desc = "Dream forest";
long_desc = "You are walking in dream forest.\n"+
"You feel that all your dreams become true in this place.\n";
}
