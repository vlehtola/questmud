#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.

inherit "room/room";
object mon,mon2,mon3;
#include "/wizards/astarel/areas/beldor/misc/descs1.c"
reset(arg) {
	if(!mon){
	        mon = clone_object(PATH+"/mobs/animal1.c");
	        move_object(mon, this_object());
	}
	if(!mon2){
		mon2 = clone_object(PATH+"/mobs/animal1.c");
		move_object(mon2, this_object());
	}
	if(!mon3){
		mon3 = clone_object(PATH+"/mobs/animal1.c");
		move_object(mon3, this_object());
	}
	
  if(arg) return;
  
  set_short("A path in thick forest.");
  set_long(getlong());
  set_items(({"path","Path is covered with thick bottomflora and its quite hard to to see.\n"+
	                "Ants and beetles are swarming all over it.\n",
	         "oak","These massive trees has thick and hard bark covering their trunk.\n",
	         "oaks","These massive trees has thick and hard bark covering their trunk.\n",
            }));
	                
add_exit("north",PATH+"rooms/forest7");
add_exit("south",PATH+"rooms/bridge");

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