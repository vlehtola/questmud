#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.
inherit "room/room";
object monster;
reset(arg) {
	if(!monster){
	monster = clone_object(PATH+"mobs/btroll");
	move_object(monster,TO);
}

  if(arg) return;
  
  set_short("The bridge.");
  set_long("Nice bridge\n");
  	                
add_exit("north",PATH+"rooms/forest10");
add_exit("south",PATH+"rooms/2forest1");
}

