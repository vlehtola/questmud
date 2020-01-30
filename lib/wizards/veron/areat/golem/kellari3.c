inherit "room/room";


object monster,monster2,monster3,monster4;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/guard");
    move_object(monster, this_object()); 
if(!monster2) { 
    monster2 = clone_object("/wizards/veron/areat/golem/mobs/guard2");
    move_object(monster2, this_object());
  if(!monster3) { 
    monster3 = clone_object("/wizards/veron/areat/golem/mobs/guard2");
    move_object(monster3, this_object());
if(!monster4) { 
    monster4 = clone_object("/wizards/veron/areat/golem/mobs/guard3");
    move_object(monster4, this_object());


 }}}}

add_exit("east","/wizards/veron/areat/golem/kellari2.c");
add_exit("down","/wizards/veron/areat/golem/kellari4.c");


  short_desc = "A comfortable room";

  long_desc = "This room looks quite comfortable out. There are four beds in here\n"+
		  "and there's some fresh hay on the floor, giving the room a pleasant\n"+
		  "smell. An oil lamp is hanging from the ceiling. Spiral stairs lead\n"+
		  "downstairs here.\n";
		  
  items = allocate(4);
  items[0] = "hay";
  items[1] = "Fresh looking hay covers the cold granite floor";
  items[2] = "lamp";
  items[3] = "An oil lamp burns brightly";
	
set_not_out(1);	
  }
