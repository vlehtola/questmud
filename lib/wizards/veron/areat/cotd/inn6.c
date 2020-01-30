inherit "room/room";
reset(arg) {
if(arg) return;

add_exit("south","/wizards/veron/areat/cotd/inn3.c");


  short_desc = "Guestroom";

  long_desc = "A cheap-looking guestroom of the inn. The room is almost\n"+
              "empty, there's only a plain wooden bed placed against the\n"+
	      "western wall under the window. A cracked wooden shelf has been\n"+
              "attached to the wall in the other end of the room. The room's\n"+
              "door has fallen off and lies in the room in the east.\n";
            
              
  set_not_out(1);
  items = allocate(6);
  items[0] = "bed";
  items[1] = "A plain bed made of planks. It doesn't look too comfortable";
  items[2] = "window";
  items[3] = "The small window offers a sight to the main street";
  items[4] = "shelf";
  items[5] = "An ugly wooden shelf attached to the wall";

 
 	
  }
