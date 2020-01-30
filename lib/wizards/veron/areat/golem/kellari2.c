inherit "room/room";



object monster,monster2;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/imp");
    move_object(monster, this_object());
if(!monster2) { 
    monster2 = clone_object("/wizards/veron/areat/golem/mobs/imp");
    move_object(monster2, this_object());

  }
}

add_exit("west","/wizards/veron/areat/golem/kellari3.c");
add_exit("ladder","/wizards/veron/areat/golem/kellari.c");
  set_light(1);
  short_desc = "A cellar";

  long_desc = "A blank-looking room. The room's granite walls are very \n"+
		  "slimy and there's moss growing in the floor. Some chains\n"+
		  "have been attached to the walls. It's almost dark in  \n"+
		  "here. The western wall has a text engraved to it.\n";
		  
  items = allocate(4);
  items[0] = "chains";
  items[1] = "Metal chains attached to wall. Probably meant for prisoners";
  items[2] = "text";
  items[3] = "The text reads 'I'm hungry'";
	set_not_out(1);	
  }