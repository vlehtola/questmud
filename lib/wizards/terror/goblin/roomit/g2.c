inherit "room/room";
inherit "room/door";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gpeon.c");
move_object(monster, this_object());
}
if(arg) return;
add_exit("west","/wizards/terror/goblin/roomit/g3.c");
add_exit("south","/wizards/terror/goblin/roomit/g8.c");
add_exit("east","/wizards/terror/goblin/roomit/g10.c");
add_exit("north","/wizards/terror/goblin/roomit/g1.c");
short_desc = "A deep forest";
long_desc = "You are in deep forest.\n"+
"You see some figures running behind trees.\n"+
"You feel that someone is laughing at you.\n"+
"You have some feeling .... that someone is looking at you.\n";
}
