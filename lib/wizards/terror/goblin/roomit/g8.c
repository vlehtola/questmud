inherit "room/room";
object monster;
object sign;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/terror/goblin/mokot/ghunter.c");
move_object(monster, this_object());
sign = clone_object("/wizards/terror/goblin/roomit/sign.c");
move_object(sign, this_object());
}
add_exit("north","/wizards/terror/goblin/roomit/g2.c");
add_exit("south","/wizards/terror/goblin/roomit/g7.c");
short_desc = "A deep forest";
long_desc = "This part of the forest is diffrent from the rest, the ground is\n"
+
"bare and devoid of life. A group of bushes seems to beckon you closer.\n";
"You see some trees and eyes looking ant you behind those.\n"+
"The  ground look funny because there is no grass on it. \n";
} 
init() {
::init();
add_action("enter", "enter");
}

enter(str) {
write("As you enter the bushes you feel that you are falling in some hole.\n");
say(this_player()->query_name()+" enters the bushes.\n");
move_object(this_player(), "/wizards/terror/goblin/roomit/s1.c");
say(this_player()->query_name()+ "falls from high but seems that he didn't hurt himself.\n");
}
