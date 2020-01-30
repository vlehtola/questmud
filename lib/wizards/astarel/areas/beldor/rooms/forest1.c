#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.

inherit "room/room";
object mon,mon2;
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
	
  if(arg) return;
  
  set_short("A path in a thick forest.");
  set_long(
"Path lands from the top of the mountain between the mountain walls\n"+
"to the mountain pass. Path is surrounded by massive bushes and covered\n"+
"with a thick bottom flora. Birds are singing beautifully and wind\n"+
"calmly wishpers its endless song.\n");
   set_items(({"path","Path is covered with thick bottomflora and its quite hard to to see.\n",
	         "bush","These massive green bushes doesnt have any berries and they\n"+
	                       "slightly rasps in wind.\n",
		 "bushes","These massive green bushes doesnt have any berries and they\n"+
	                       "slightly rasps in wind.\n",
	                }));
              
add_exit("north","/wizards/astarel/workroom");
add_exit("southeast",PATH+"rooms/forest2");
add_exit("south",PATH+"rooms/forest3");
add_exit("southwest",PATH+"rooms/forest4");
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