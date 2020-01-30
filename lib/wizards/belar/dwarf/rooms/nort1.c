inherit "room/room";
object monster;
object monster2;
object monster3;

reset(arg) {
if(!monster);
if(!monster2);
if(!monster3) {
monster = clone_object("/wizards/belar/dwarf/monsters/gdwc1.c");
monster2 = clone_object("/wizards/belar/dwarf/monsters/gdwc2.c");
monster3= clone_object("/wizards/belar/dwarf/monsters/gdwc3.c");
move_object(monster, this_object());
move_object(monster2, this_object());
move_object(monster3, this_object());
}
add_exit("north","/wizards/belar/dwarf/rooms/nort2.c");
add_exit("south","/wizards/belar/dwarf/entrance.c");
add_exit("west","/wizards/belar/dwarf/rooms/weside1.c");
add_exit("east","/wizards/belar/dwarf/rooms/easide1.c");
short_desc = " The streets of Velour ";
long_desc ="########### The Velour city. You are standing on the crossing of mainstreet\n"+ 
  	   "#Inn |  AR# and T'jul street. Mainstreet leads to north and seems to be\n"+
	   "#-+--*--+-# very crowded. Also you can see guards watching for troublemakers\n"+
           "#===]|[===# and thieves on a northern road. T'jul street has a smith and an inn\n"+
	   "########### along it.If you need a place to rest or get a caravan to Duranghom\n"+
           "just ask about it at the inn.\n"+
	   "T'jul street leads west and east. Mainstreet leads to north.\n";
}

