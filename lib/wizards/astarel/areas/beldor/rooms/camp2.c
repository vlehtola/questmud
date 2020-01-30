#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.
inherit "room/room";


reset(arg) {
	
  if(arg) return;
  
  set_short("Frontyard of the castle.");
  set_long("poks\n");
  
  add_exit("northwest",PATH+"rooms/camp6");
  add_exit("east",PATH+"rooms/camp3");

 
}