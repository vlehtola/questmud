#define AREAPATH "wizards/nalle/plateau/"

inherit "room/room";

object monster;

reset(arg) {
  if(arg) return;
  add_exit("out",AREAPATH+"8_-1");
  short_desc = "Inside a nice, well decorated shack";
  long_desc =
"Wow, this shack sure is pretty. Not a spec of dust anywhere,\n"+
"the room has obviously been cleaned with germanic precision.\n"+ 
"Beautiful pink curtains have been drawn in front of the windows\n"+
"to shield the hut's inhabitants from prying eyes. A desk with some\n"+
"miscellaneous paraphernalia lies next to a pretty little bed. A\n"+
"small wooden door leads out.\n";
  
  items = allocate(8);
  items[0] = "desk";
  items[1] = "Some porcelain figurines of little piggies and bears\n"+
	     "have been placed on the desk. Also a card reading : \n"+
	     "'This bottle, to my only love! Please take me back,\n"+
	     " Yours, Armin.' has been left on the desk.\n";
  items[2] = "curtains";
  items[3] = "Pretty pink curtains have been drawn in front of the window.\n";
  items[4] = "window";
  items[5] = "Pretty pink curtains have been drawn in front of the window.\n";
  items[6] = "bed";
  items[7] = "A nice little bed with a desk next to it.\n";

if(!monster)    {
 monster = clone_object(AREAPATH+"monsters/girlfriend");
 move_object(monster, this_object());
                }
}

