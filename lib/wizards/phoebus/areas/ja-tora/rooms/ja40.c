inherit "room/room";
object monster;
object monster2;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/t_hunter");
move_object(monster, this_object());
}

if(!monster2) {
monster2 = clone_object("/wizards/phoebus/areas/ja-tora/monsters/t_guard");
move_object(monster2, this_object());
}

if(arg) return;

add_exit("north","/wizards/phoebus/areas/ja-tora/rooms/ja41.c");
add_exit("west","/wizards/phoebus/areas/ja-tora/rooms/ja32.c");

short_desc = "Dark passage";
long_desc = "The dark passage continues here. Strange but even with \n"+
                      "a light source its still very dark here, and a strong sense of evil can \n"+
                      "be felt in this place. The walls here are rough and corsely made.\n";
}
