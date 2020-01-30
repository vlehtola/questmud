inherit "room/room";
object monster;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/g_child");
move_object(monster, this_object());
}

if(arg) return;

add_exit("north","/wizards/phoebus/areas/ja-tora/rooms/ja7");
add_exit("south","/wizards/phoebus/areas/ja-tora/rooms/ja4");
add_exit("west","/wizards/phoebus/areas/ja-tora/rooms/ja2");
add_exit("east","/wizards/phoebus/areas/ja-tora/rooms/ja10");

short_desc = "Centre Square of Ja-Tora";
long_desc  = "You stand in the middle of the Village 'Ja-Tora'. This small \n"+
                           "village is owned by a small group of Gnomes. The village has been \n"+
                           "located beside a small range of mountains for extra protection and is\n"+
                           "surrounded by a tall, strong wooden fence. \n";                          
}
