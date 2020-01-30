inherit "room/room";
object monster;

reset(arg) {
if(!monster){
monster = clone_object("/wizards/belar/dwarf/monsters/gdwc1.c");
move_object(monster, this_object());
}
add_exit("north","/wizards/belar/dwarf/rooms/dwcs.c");
add_exit("south","/wizards/belar/dwarf/rooms/nort1.c");
add_exit("west","/wizards/belar/dwarf/rooms/hut4.c");
short_desc = "A pebble road";
long_desc = "########### This is mainstreet of Valour which is going north and south.\n"+
	    "#    |    # This newly build street is usually crowded with dwarfs and\n"+
  	    "# SH-*    # different travellers that search their fortune from this\n"+
	    "#    |  AR# small city. Busily looking for a place to stay for the\n"+
	    "########### night. Before their long travels. To west is an itemshop.\n"+
	    "to north is Valour's Central Square.\n";

  items = allocate(4);
  items[0] = "road";
  items[1] = "The road is consisted from small rocks, which are carefully placed to the ground";
  items[2] = "woman";
  items[3] = "it's an old woman. What did you expect ?";
}

