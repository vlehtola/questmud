inherit "room/room";
object monster;

reset(arg) {
if(!monster) {
monster = clone_object("/wizards/belar/dwarf/monsters/gdw1.c");
move_object(monster, this_object());
}
add_exit("north","/wizards/belar/dwarf/rooms/nort1.c");
add_exit("west","/wizards/belar/dwarf/rooms/wal1.c");
short_desc = "The gates of dwarf city";
long_desc = "You are standing at the entrance of the city called Velour. Strong\n"+
            "iron gates guard the road to city. The city walls remind you about\n"+
            "ancient culture. There is a small hut in the west.\n"+
            "A sign is hanging over the gates.\n";

}

