#include "/sys/ansi.h"
inherit "room/room";
#define TP this_player()
#define COPIER "/stronghold/daemons/copier"

reset(arg){
if (arg) return;

set_long(BOLD+YELLOW_F+"\n"+
"\n"+

"                        ' \n"+
"                     \\  ,  / \n"+
"                 ' ,___/_\\___, ' \n"+
"                    \\ /o o\\ /   \n"+
"                -=   > \\_/ <   =- \n"+
"                    /_\\___/_\\     \n"+
"                 . `   \\ /   ` .   \n"+
"                     /  `  \\      \n"+
"                        . \n"+

"   \n"+
"\n"+
"\n"+
         
         BOLD+BLUE_F+WHITE_B+"Astarel"+OFF+"'s workroom.\n"+
         "Roomcmds: "+BOLD+"rgogo"+OFF+","+BOLD+"freereinc"+OFF+"\n");
         

add_exit("cs","/world/city/cs");
add_exit("post","/world/city/post");
add_exit("inn","/world/city/inn");
add_exit("plaque","/world/city/adventurers_hall");
add_exit("lottery","/daemons/lotto");
add_exit("freereinc","/world/special/free_reinc_room");
add_exit("ban","/room/banroom");
}

init() {
  ::init();
  /*
  
  	add_action("room_goto","rgogo");
	add_action("bunny_query_map", "bunny_map");
	add_action("start_bunny_event", "start_bunny");
	add_action("add_bunny_hunters", "add_hunter");
	add_action("add_bunny_score", "add_score");
	add_action("junttila", "juntti");
	add_action("get_sword","get_sword");
	*/
	add_action("testi","testi");		
}

status testi() {
	COPIER -> copy_file("/wizards/astarel/workroom.c","/wizards/astarel/workroom2.c");
	return 1;
}



status get_sword() {
	
	object ob;
	ob = clone_object("/wizards/astarel/chaos_knights/obj/ck_blade.c");
	
	ob->set_owner(this_player()->query_name());
	
}


status junttila() {
	find_player("bud")->remove_scar();
	return 1;
}

status add_bunny_score(string str) {
	
	string name;
	int i;
	
	sscanf(str, "%s %d",name,i);
	
	"/wizards/astarel/events/b_hunt/bunny_d"->add_bunny_score(name,i);
	return 1;
}

	
status add_bunny_hunters(string str) {
	if(!str) return 1;
	"/wizards/astarel/events/b_hunt/bunny_d"->add_bunnyhunter(str);
	return 1;
}

status start_bunny_event() {
	"/wizards/astarel/events/b_hunt/bunny_d"->start_bunny_event();
	return 1;
}


status bunny_query_map() {
	
string *str;
mapping mapp;
int i;
	mapp = "/wizards/astarel/events/b_hunt/bunny_d"->query_hunters();
	str = m_indices(mapp);
	
	for(i=0;i<sizeof(str);i++) {
		write(" "+str[i]+"  "+mapp[str[i],0]+" "+mapp[str[i],1]+" "+mapp[str[i],2]+" "+mapp[str[i],3]+" "+mapp[str[i],4]+" \n");
	}
		
return 1;
}



status room_goto(string str) {
if(!str) { 
write("Usage: rgogo <wizard>\n");
return 1;
}
if(str) {
write("Going to "+capitalize(str)+"'s workroom.\n");
move_object(TP,"/wizards/"+str+"/workroom.c");
return 1;
}
}
