inherit "room/room";
object monster;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/troll_m");
move_object(monster, this_object());
}

if(arg) return;

add_exit("south","/wizards/phoebus/areas/ja-tora/rooms/ja38");

short_desc = "Smelly cavern";
long_desc = "When you enter this cavern you now notice that the female, hanging \n"+
                      "from shackles is not moving or making any sound. Maybe thats due to \n"+
                      "her missing a her right leg. Bits of bone and rotten flesh lie about the \n"+
                      "area making you very sick.\n";
}

