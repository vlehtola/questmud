#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.
inherit "room/room";

reset(arg) {
	

  if(arg) return;
  
  set_short("The castle's gate.");
  set_long("Huge gate rises in front of you\n");
  	                
add_exit("north",PATH+"rooms/2forest10");
add_exit("northwest",PATH+"rooms/2forest9");

}

