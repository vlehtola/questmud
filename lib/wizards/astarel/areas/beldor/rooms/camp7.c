#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.
inherit "room/room";


reset(arg) {
	
  if(arg) return;
  
  set_short("Frontyard of the castle.");
  set_long("poks\n");
  
  add_exit("northwest",PATH+"rooms/camp11");
  add_exit("south",PATH+"rooms/camp3");
  add_exit("southeast",PATH+"rooms/magetent");
  add_exit("east",PATH+"rooms/chieftent");
  

 
}