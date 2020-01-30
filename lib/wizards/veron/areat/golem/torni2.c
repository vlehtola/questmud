inherit "room/room";


object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/fgolem");
    move_object(monster, this_object());

}

add_exit("north","/wizards/veron/areat/golem/parveke.c");
add_exit("up","/wizards/veron/areat/golem/paajehu.c");
add_exit("down","/wizards/veron/areat/golem/torni1.c");




  short_desc = "In a tower";

  long_desc = "There's no doubt that this is a tower. This is a small round room with a \n"+
		  "staircase coming from downstairs and continuing upstairs. A large tub \n"+
		  "full of sun flower seeds is on the floor. A fragile-looking wooden door\n"+
		  "in the north leads to some kind of a balcony. An uncomfortable-looking\n"+
		  "bed is placed next to the balcony door.\n";
              
		  
  items = allocate(4);
  items[0] = "tub";
  items[1] = "A large tub full of sun flower seeds. They're probably used for feeding birds";
  items[2] = "bed";
  items[3] = "An uncomfortable-looking small wooden bed";
set_not_out(1);		
  }