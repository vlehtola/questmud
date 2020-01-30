#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.
inherit "room/room";


reset(arg) {
	
  if(arg) return;
  
  set_short("Frontyard of the castle.");
  set_long("poks\n");
  
  add_exit("north",PATH+"rooms/castleentrance");
  add_exit("east",PATH+"rooms/castle3");
  add_exit("west",PATH+"rooms/castle2");
  add_exit("southeast",PATH+"rooms/castle7");
  add_exit("southwest",PATH+"rooms/castle5");
  add_exit("south",PATH+"rooms/castle6");
 
}