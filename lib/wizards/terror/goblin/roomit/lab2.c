inherit "room/room";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gguard.c");
move_object(monster, this_object());
}
add_exit("east","/wizards/terror/goblin/roomit/lab3.c");
add_exit("west","/wizards/terror/goblin/roomit/lab1.c");
short_desc = "A path behind bushes";
long_desc = "You have found the path leading to goblin laboratory.\n"+
"Be careful it can be dangerous in there.\n"+
"As you approch the laboratory you can smell the chemicals in air.\n"+
"That smell is terrible and you feel that you could vomit.\n";
}

