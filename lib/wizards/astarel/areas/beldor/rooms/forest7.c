#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.

inherit "room/room";

#include "/wizards/astarel/areas/beldor/misc/descs1.c"
reset(arg) {

  if(arg) return;
  
  set_short("A path in thick forest.");
  set_long(getlong());
  set_items(({"path","Path is covered with thick bottomflora and its quite hard to to see.\n"+
	                "Ants and beetles are swarming all over it.\n",
	         "oak","These massive trees has thick and hard bark covering their trunk.\n",
	         "oaks","These massive trees has thick and hard bark covering their trunk.\n",
            }));
	                
add_exit("south",PATH+"rooms/forest10");
add_exit("northeast",PATH+"rooms/forest5");
add_exit("east",PATH+"rooms/forest12");

}

init(){
	::init();
	add_action("listen","listen");
}

status listen(){
	tell_object(this_player(),"You listen the singing birds, its so beautiful.\n"+
	                          "You almost fall in trance.\n");
	 return 1;
	 
	 }