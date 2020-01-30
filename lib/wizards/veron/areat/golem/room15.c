inherit "room/room";


reset(arg) {
if(arg) return;


add_exit("west","/wizards/veron/areat/golem/room12.c");
add_exit("north","/wizards/veron/areat/golem/room16.c");
add_exit("southeast","/wizards/veron/areat/golem/room17.c");



  short_desc = "A livingroom";

  long_desc = "A comfortable looking livingroom. Furry carpets are placed on the\n"+
		  "floor. There are three fluffy-looking sofas in the middle of the \n"+
		  "room, forming a circle with a small table in the middle. Three decks \n"+
		  "of cards are placed on the table. Someone has been undoubtely playing \n"+
		  "not long ago. A chandelier is hanging over the table. Some colorful  \n"+
		  "pictures are hanging on the walls.\n";
		  

              		  
  items = allocate(14);
  items[0] = "carpets";
  items[1] = "Furry, soft carpets. They feel warm";
  items[2] = "sofas";
  items[3] = "Three very comfortable looking sofas";
  items[4] = "table"; 
  items[5] = "A small round table. There are three decks of cards on it";
  items[6] = "decks";
  items[7] = "Three decks of colorful cards. The backs of the cards read:'Magic:the gathering'";
  items[8] = "cards";
  items[9] = "Three decks of colorful cards. The backs of the cards read:'Magic:the gathering'";
  items[10] = "chandelier";
  items[11] = "A quite large and probably very expensive chandelier is hanging over the table";
  items[12] = "pictures";
  items[13] = "Colorful pictures of flowers";


 set_not_out(1);
		
  }
