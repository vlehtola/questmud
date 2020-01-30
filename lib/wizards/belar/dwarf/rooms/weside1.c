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
add_exit("north","/wizards/belar/dwarf/rooms/hut2.c");
add_exit("west","/wizards/belar/dwarf/rooms/weside2.c");
add_exit("east","/wizards/belar/dwarf/rooms/nort1.c");
short_desc = "The west alley of Velour";
long_desc = "########### You are standing at T'jul street. Dwarves\n"+
            "#|  Inn  |# are lazy and havent finished this road yet. You can hear noise\n"+
            "#+---*---+# from north, it's like someone is fighting in there.\n"+
            "#=======]|# To north is a huge building which has no windows at all.\n"+
            "########### A solid steel door blocks the way to the building \n"+
   	    "T'jul street leads west and east.\n";
items = allocate(2);
  items[0] = "road";
  items[1] = "The road is very dirty, but there is small golden heaps on the ground";
}

