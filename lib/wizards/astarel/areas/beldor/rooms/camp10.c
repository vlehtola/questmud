#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.
inherit "room/room";


reset(arg) {
	
  if(arg) return;
  
  set_short("Frontyard of the castle.");
  set_long("poks\n");
  
  add_exit("west",PATH+"rooms/camp9");
  add_exit("north",PATH+"rooms/camp15");
  add_exit("east",PATH+"rooms/camp11");
  add_exit("southwest",PATH+"rooms/camp5");
 
 
}