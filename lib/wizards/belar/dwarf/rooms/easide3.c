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
add_exit("north","/wizards/belar/dwarf/rooms/easide5.c");
add_exit("south","/wizards/belar/dwarf/rooms/easide2.c");
short_desc = "The east alley of Velour";
long_desc = "########### You are standing at Balter street. Guards on this\n"+
            "#    | W  # are tripled because someone tried to blow up a building\n"+
            "#    * W  # last week in here.\n"+
            "#AR  | W  # Also some ogres were seen on this street last week. \n"+
	    "########### \n"+ 
	    "Balter street leads west and east.\n";

items = allocate(4);
  items[0] = "road";
  items[1] = "The road is very dirty, but there is small golden heaps on the ground";
  items[2] = "door";
  items[3] = "The door is thightly shut";
}

