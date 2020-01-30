inherit "room/room";
reset(arg) {
if(arg) return;
add_exit("east","/wizards/veron/workroom.c");
add_exit("mansion","/wizards/veron/areat/golem/room1.c");
add_exit("cotd","/wizards/veron/areat/cotd/street1.c");


  short_desc = "Area teleport room";

  long_desc = "Area teleportti huaane\n"; 	

 property = allocate(1);
  property[0] = "no_summon";
             

		
  }
