inherit "room/room";
object monster;
object monster2;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/g_priest");
move_object(monster, this_object());
}

if(!monster2) {
monster2 = clone_object("/wizards/phoebus/areas/ja-tora/monsters/g_guard");
move_object(monster2, this_object());
}

if(arg) return;

add_exit("west","/wizards/phoebus/areas/ja-tora/rooms/ja5");

short_desc = "Ja-Tora Church";
long_desc = "This building is much more lavish than the rest you've seen sofar. Great  \n"+
                      "tapestrys line ever wall, depicting battles and other events. Against the  \n"+
                      "western wall rests a largestatue of what seems to be a God of somekind. \n"+
                      "Leading up to the statue are a numberbenches for sitting and praying.\n";
}



