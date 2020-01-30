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
add_exit("south","/wizards/belar/dwarf/rooms/hut8.c");
add_exit("west","/wizards/belar/dwarf/rooms/weside4.c");
add_exit("east","/wizards/belar/dwarf/rooms/dwcs.c");
short_desc = "The crossing of T'jul and Rhat'z street";
long_desc = "############ You are standing at Gladius street\n"+
            "#|       | # This street is very crowded.\n"+
            "#|---*--(c)# .\n"+
            "#|   T   | # Buildings in Gladius street are very luxury indeed.\n"+
            "############ This street is ... \n"+
   	    "Gladius street leads west and east.\n";

items = allocate(2);
  items[0] = "road";
  items[1] = "The road is very dirty, but there is small golden heaps on the ground";
}

