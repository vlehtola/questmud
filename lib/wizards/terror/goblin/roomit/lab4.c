inherit "room/room";
object monster;
reset(arg) {
monster = clone_object("/wizards/terror/goblin/mokot/gkemisti.c");
move_object(monster, this_object());
add_exit("southeast","/wizards/terror/goblin/roomit/lab3.c");
short_desc = "The goblin laboratory";
long_desc = "You have entered the goblin laboratory.\n"+
"This mad chemist isn't healthy so be carefuly it isn't cool to get acid on your face.\n"+
"Here you can smell the chemicals in air.\n"+
"That smell is terrible and you feel that you could vomit.\n"+
"You tremble when chemist mixes his chemicals.\n";

}

