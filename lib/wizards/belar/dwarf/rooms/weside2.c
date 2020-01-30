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
add_exit("north","/wizards/belar/dwarf/rooms/weside4.c");
add_exit("east","/wizards/belar/dwarf/rooms/weside1.c");
short_desc = "The crossing of T'jul and Rhat'z street";
long_desc = "########### You are standing at crossing of T'jul street and\n"+
            "#  W | Inn# Gorran street. Gorran street looks abandoned.\n"+
            "#  W *---+# This place is so quiet, nobody uses this road.\n"+
            "#  W======# Buildings in Gorran street have no windows and their doors\n"+
            "########### are nailed shut as if nobody lives in here. \n"+
   	    "Rhat'z leads north and T'jul street leads east.\n";

items = allocate(2);
  items[0] = "road";
  items[1] = "The road is very dirty, but there is small golden heaps on the ground";
}

