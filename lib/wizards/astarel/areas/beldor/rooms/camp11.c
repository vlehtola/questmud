#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.
inherit "room/room";


reset(arg) {
	
  if(arg) return;
  
  set_short("Frontyard of the castle.");
  set_long("poks\n");
  
  add_exit("west",PATH+"rooms/camp10");
  add_exit("north",PATH+"rooms/camp16");
  add_exit("east",PATH+"rooms/camp19");
  add_exit("southwest",PATH+"rooms/camp6");
  add_exit("southeast",PATH+"rooms/camp7");

 
}