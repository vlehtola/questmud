inherit "room/room";
object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/cotd/mobs/mayor");
    move_object(monster, this_object());
  }

if(arg) return;
add_exit("south","/wizards/veron/areat/cotd/mayor1.c");


  short_desc = "Mayor's room";

  long_desc = "This place looks like the workroom of the town's mayor. \n"+
              "Two large bookshelves full of books are placed next to the\n"+	   
	      "eastern wall. The mayor's desk is opposite the bookshelves,\n"+
              "with some large candles on it. There's a weird-looking bear\n"+
              "skin pelt on the floor.\n";
              
  set_not_out(1);
  items = allocate(8);
  items[0] = "bookshelves";
  items[1] = "Two large bookshelves full of books. They're placed next to the eastern wall";        
  items[2] = "desk";
  items[3] = "A wooden desk. There are some large candles on it";
  items[4] = "candles";
  items[5] = "The candles are on the mayor's desk. There's nothing special in them";
  items[6] = "pelt";
  items[7] = "The bear skin pelt looks kinda weird. Looks like it's moving";

 	
  }
