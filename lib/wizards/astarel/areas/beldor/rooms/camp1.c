#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.
inherit "room/room";


reset(arg) {
	
  if(arg) return;
  
  set_short("Frontyard of the castle.");
  set_long("poks\n");
  
  add_exit("northwest",PATH+"rooms/camp4");
  add_exit("north",PATH+"rooms/camp5");
  add_exit("west",PATH+"rooms/2forest11");

 
}