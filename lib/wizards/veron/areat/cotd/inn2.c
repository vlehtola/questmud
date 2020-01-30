inherit "room/room";

object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/cotd/mobs/carcass");
    move_object(monster, this_object());
  }

if(arg) return;

add_exit("west","/wizards/veron/areat/cotd/inn1.c");


  short_desc = "Restaurant";

  long_desc = "This is the part of the inn where the customers eat. There are two\n"+
              "large wooden tables with stools around them placed in the middle of\n"+
	      "the hall. Five beer barrels are lined up in the eastern end of the\n"+
              "hall. Remnants of a meal rot on the table. A small nest made of some\n"+
              "animal can be spotted between the beer barrels. The hall continues to\n"+
              "the west.\n";
            
              
  set_not_out(1);
  items = allocate(12);
  items[0] = "tables";
  items[1] = "Large and sturdy wooden tables";
  items[2] = "stools";
  items[3] = "Sturdy wooden stools placed around the tables";
  items[4] = "barrels";
  items[5] = "Five big beer barrels. They've been lined up in the eastern end of the hall and\n"+
             "are surely empty";
  items[6] = "remnants";
  items[7] = "Remnants of a meal rotting on the table";
  items[8] = "meal";
  items[9] = "Remnants of a meal rotting on the table";
  items[10] = "nest";
  items[11] = "A small nest made of twigs";
  
 
 	
  }
