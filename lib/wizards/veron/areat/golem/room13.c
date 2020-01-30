inherit "room/room";


object monster;
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/cook");
    move_object(monster, this_object());
  }

add_exit("west","/wizards/veron/areat/golem/room14.c");
add_exit("east","/wizards/veron/areat/golem/room12.c");

  short_desc = "The kitchen";

  long_desc = "This room is undoubtedly a kitchen. Some ovens warmed up with\n"+
		  "firewood give some warmth here. Long tables are full of delicatessen.\n"+
		  "Large cauldrons bubble on stoves located next to the eastern wall.\n"+
		  "A nice smells drifts in the room.\n";
                
		  

  items = allocate(6);
  items[0] = "ovens";
  items[1] = "Some messy ovens. They're warmed up with firewood";
  items[2] = "delicatessen";
  items[3] = "Today's cold supper";
  items[4] = "cauldron";
  items[5] = "You take a look at one of the cauldrons. There's peasoup bubbling\n"+
             "inside it";             
set_not_out(1);
		
  }