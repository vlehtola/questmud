#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.
inherit "room/room";

reset(arg) {



  if(arg) return;
  
  set_short("Path in a thick forest.");
  set_long("poks\n");
  	                
add_exit("north",PATH+"rooms/2forest5");
add_exit("southeast",PATH+"rooms/2forest9");
add_exit("west",PATH+"rooms/2forest12");


}