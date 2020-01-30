inherit "room/room";
object monster;
object monster2;

reset(arg) {
if(!monster);
if(!monster2) {
monster = clone_object("/wizards/belar/dwarf/monsters/gdwc1.c");
monster2 = clone_object("/wizards/belar/dwarf/monsters/wedw1.c");
move_object(monster, this_object());
move_object(monster2, this_object());
}
add_exit("north","/wizards/belar/dwarf/rooms/hut3.c");
add_exit("west","/wizards/belar/dwarf/rooms/nort1.c");
add_exit("east","/wizards/belar/dwarf/rooms/easide2.c");
short_desc = "The east alley of Velour";
long_desc = "########### You are standing at T'jul street. You can hear a loud\n"+
            "#|   AR  |# banging noise from north, it's like someone is forging in there.\n"+
            "#+---*---+# To north is a building which is build from those little rocks.\n"+
            "#|[=======# A solid metal door blocks the way to the building.\n"+
	    "########### T'jul street leads west and east.\n";

items = allocate(4);
  items[0] = "road";
  items[1] = "The road is very dirty, but there is small golden heaps on the ground";
  items[2] = "door";
  items[3] = "The door is thightly shut";
}

