inherit "room/room";
object monster;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/g_mayor");
move_object(monster, this_object());
}

if(arg) return;

add_exit("west","/wizards/phoebus/areas/ja-tora/rooms/ja11");

short_desc = "Mayor's House";
long_desc = "This house has about four rooms and is furnished much better that the  \n"+
                      "other houses you've seen. Proper chairs and table, even a few pictures \n"+
                      "hang from the walls.\n";
}
