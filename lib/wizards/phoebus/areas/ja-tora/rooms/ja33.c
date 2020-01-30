inherit "room/room";
object monster;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/troll_s");
move_object(monster, this_object());
}

if(arg) return;

add_exit("north","/wizards/phoebus/areas/ja-tora/rooms/ja34");
add_exit("south","/wizards/phoebus/areas/ja-tora/rooms/ja30");

short_desc = "Dark passage";
long_desc = "Standing in this dark area you can hear strange noises coming \n"+
                      "from the north of here. The walls of these passages have been \n"+
                      "roughly made, the scrape marks remain from the tools used to \n"+
                      "create it. The passage continues north and south.\n";
}

