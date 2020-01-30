inherit "room/room";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("wizards/terror/goblin/mokot/gguard2.c");
move_object(monster, this_object());
}
add_exit("northwest","/wizards/terror/goblin/roomit/lab4.c");
add_exit("west","/wizards/terror/goblin/roomit/lab2.c");
short_desc = "A path behind bushes";
long_desc = "You have found the path leading to goblin laboratory.\n"+
"Be careful it can be dangerous in there.\n"+
"As you approach the laboratory you can smell the chemicals in air.\n"+
"That smell is terrible and you feel that you could vomit.\n"+
"You can hear some laughing from northwest and you feel that laughter isn't healthy.\n";

}

