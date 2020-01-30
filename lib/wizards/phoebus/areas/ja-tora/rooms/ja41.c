inherit "room/room";
object monster;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/t_guard");
move_object(monster, this_object());
}

if(arg) return;

add_exit("south","/wizards/phoebus/areas/ja-tora/rooms/ja40.c");
add_exit("east","/wizards/phoebus/areas/ja-tora/rooms/ja42.c");

short_desc = "Dark passage";
long_desc = "The dark passage continues here. Strange but even with \n"+
                      "a light source its still very dark here, and a strong sense of evil can \n"+
                      "be felt in this place. The walls here are rough and corsely made.\n";
}
