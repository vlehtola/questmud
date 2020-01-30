inherit "room/room";
object monster;
reset(arg) {
if(!monster){
monster = clone_object("/wizards/belar/dwarf/monsters/dwcl1.c");
move_object(monster, this_object());
}

add_exit("north","/wizards/belar/dwarf/rooms/nort3.c");
add_exit("south","/wizards/belar/dwarf/rooms/nort2.c");
add_exit("east","/wizards/belar/dwarf/rooms/easide4.c");
add_exit("west","/wizards/belar/dwarf/rooms/weside5.c");
short_desc = "The central squate of Valour";
long_desc = "###########The central square of valour is very beatifully decorated.\n"+
            "#    | off#earth is covered with very small rocks, there is water in a little\n"+
            "#-+-(*)-+-#fountain. Square is very crowded and there is a statue of a dwarf\n"+
            "# T  |    #There is a Sign.\n"+
	    "########### \n";
  items = allocate(6);
  items[0] = "fountain";
  items[1] = "Fountain is really beautiful, it is carved of ivory.\n"+
	     "There is a small flowerbench surrounding the fountain.\n";
  items[2] = "statue";
  items[3] = "The statue is carved from mithril it has a strange green glow.\n"+
 	     "a small plaque reads : For the honor of G'norr for saving our city\n";
  items[4] = "sign";
  items[5] = " The  sign  reads  :\n"+
	     " Cave entrance to North \n"+
	     " Smith to East \n"+
	     " R'hatz tavern to West \n";
}	     
	
