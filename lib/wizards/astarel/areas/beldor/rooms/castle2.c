#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.
inherit "room/room";


reset(arg) {
	
  if(arg) return;
  
  set_short("Frontyard of the castle.");
  set_long("poks\n");
  
  add_exit("east",PATH+"rooms/castle1");
  add_exit("southwest",PATH+"rooms/castle4");

 
}