#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.
inherit "room/room";


reset(arg) {
	

  if(arg) return;
  
  set_short("Path in a thick forest.");
  set_long("poks\n");
  	                
add_exit("northeast",PATH+"rooms/2forest4");
add_exit("south",PATH+"rooms/2forest8");


}