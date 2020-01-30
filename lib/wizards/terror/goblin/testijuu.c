inherit "room/room";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/gpeon.c");
move_object(monster, this_object());
}
add_exit("north","/wizards/terror/goblin/roomit/g2.c");
add_exit("south","/wizards/terror/goblin/roomit/g7.c");
short_desc = "A smelly forest";
long_desc = "You smell some chemicals in the air.\n"+
"You have a funny feeling in your nose and it makes you wonder\n"+
"what the chemicals could be that produce this revolting smell. \n"+
"As you venture in the midsts of these gases you feel the cells of\n"+
"your brains slowly becoming useless and dead.You notice a somewhat.\n"+
"large hole in a thick oak.\n";
}

init() {
::init();
add_action("enter", "enter");
}

enter(str) {
write("You manage to enter the hole in the oak, but not with ease.\n");
say(this_player()->query_name()+" enters the hole in the oak.\n");
move_object(this_player(), "/wizards/terror/goblin/roomit/s1.c");
say(this_player()->query_name()+" enters the oak from outside.\n");
}
