inherit "room/room";


object monster;
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/servant");
    move_object(monster, this_object());
  }

add_exit("south","/wizards/veron/areat/golem/room1.c");
add_exit("north","/wizards/veron/areat/golem/room3.c");

  short_desc = "Entrance hall";

  long_desc = "This is the entrance hall of the mansion. There are some \n"+
              "coat racks on the western wall. Expensive-looking carpets \n"+
              "cover the floor. There's a doorway leading to the north from\n"+
	        "here. A picture of a serious-looking man is placed above\n"+
              "the doorway. It might be the picture of the master of\n"+
		  "this house.\n"; 	

  items = allocate(6);
  items[0] = "carpets";
  items[1] = "Very expensive-looking red carpets made of velvet";
  items[2] = "picture";
  items[3] = "A picture of a serious-looking man is placed above the doorway";
  items[4] = "racks";
  items[5] = "The wooden coat racks are empty";
 set_not_out(1);
set_light(3);

		
  }
