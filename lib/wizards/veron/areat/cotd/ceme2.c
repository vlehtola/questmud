inherit "room/room";
object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/cotd/mobs/carcass");
    move_object(monster, this_object());
  }

if(arg) return;
add_exit("west","/wizards/veron/areat/cotd/ceme1.c");

  short_desc = "Cemetery";

  long_desc = "The graveyard of Remick is a gloomy place. Some of the graves\n"+
              "have been digged open and some unburied corpses rot on the ground.\n"+	   
	      "Almost all the gravestones have been turned upside down.\n";
                    

  items = allocate(6);
  items[0] = "graves";
  items[1] = "Some graves have been digged open";          
  items[2] = "corpses";
  items[3] = "Some unburied corpses";
  items[4] = "gravestones";
  items[5] = "Almost all of the gravestones have been turned upside down";
 

 	
  }
