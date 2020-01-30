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
add_exit("north","/wizards/belar/dwarf/rooms/easide3.c");
add_exit("west","/wizards/belar/dwarf/rooms/easide1.c");
short_desc = "The east alley of Velour";
long_desc = "########### You are standing at crossing of T'jul street and Balter.\n"+
            "#AR  | W  # street. Balter street was named after a huge dwarf which\n"+
            "#+---* W  # killed six ogres with his bare fists. Balter street is\n"+
            "#======W  # tightly habitated and therefore this street has many guards\n"+
	    "########### to keep crimes out of this street.\n"+
	    "Balter street leads north and T'jul street leads west.\n";

items = allocate(4);
  items[0] = "road";
  items[1] = "The road is very dirty, but there is small golden heaps on the ground";
  items[2] = "door";
  items[3] = "The door is thightly shut";
}

