inherit "room/room";
inherit "room/door";
object monster;
reset(arg) {
if(!monster) {

monster = clone_object("/wizards/terror/goblin/mokot/ghunter.c");
move_object(monster, this_object());
}
if(arg) return;
add_exit("north","/wizards/terror/goblin/roomit/g8.c");
add_exit("west","/wizards/terror/goblin/roomit/g6.c");
add_exit("east","/wizards/terror/goblin/roomit/g14.c");
short_desc = "Deep Forest";
long_desc = "You are in deep forest.\n"+
"You see some figures running behind the trees.\n"+
"You feel that someone is laughing at you.\n";
}
