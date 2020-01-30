#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.
inherit "room/room";

reset(arg) {
	
  if(arg) return;
  
  set_short("The ford.");
  set_long("nice ford\n");
  set_water(1);
  	                
add_exit("north",PATH+"rooms/forest11");
}

init(){
	::init();
	add_action("cross","cross");
}

status cross(string str) {
	if(!str) {
		tell_object(TP,"Cross what?\n");
		return 1;
	}
	if(str == "river" || str == "ford") {
		if(!random(10)){
			tell_object(TP,"When you are in middle of the river, suddenly huge\n"+
			               "wave rises from nowhere and wipes you away!\n");
			TP->hit_player(TP->query_hp()/2);
			move_object(TP,"/wizards/astarel/workroom.c");
			tell_room(TO,"When "+TP->query_name()+" is in the middle of the river, suddenly huge\n"+
			                        "wave rises from nowhere and wipes him away!\n");
			
			
			return 1;
			
		}
		tell_object(TP,"You cross the river\n");
		move_object(TP,PATH+"rooms/forest11");
		tell_room(TO,TP->query_name()+" crosses the river\n");
		return 1;
	}
	tell_object(TP,"Cross what?\n");
	return 1;
}
