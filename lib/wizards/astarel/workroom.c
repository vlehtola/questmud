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
	
		add_action("marry","marri");
	}
	
status marry() {
	
	find_player("astarel")->set_married("1 bugs.\n"+
	                                    ".............................................\n"+
					    ". En leveleist� koodaa, en aksuista koodaa, .\n"+
					    ".   jos koodaan, niin koodaan muuten vain.  .\n"+
					    ".............................................\n"+
					    ".           Nothing is impossible,          .\n"+
					    ".       just mathematically improbable      .\n"+
					    "............................................");
	}
					
	                     

