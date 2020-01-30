inherit "room/room";
object monster;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/troll_f");
move_object(monster, this_object());
}

if(arg) return;

add_exit("south","/wizards/phoebus/areas/ja-tora/rooms/ja34");

short_desc = "Dirty cavern";
long_desc = "The passage opens up into a small cavern, this area seems to \n"+
                      "have been made into sleep quarters. In the northeast corner of \n"+
                      "the cavern old rotten sticks and bits of rags have been made into \n"+
                      "a bed of sorts. Also on closer observation you notice skeletal \n"+
                      "remains lying here and there.\n";
}

