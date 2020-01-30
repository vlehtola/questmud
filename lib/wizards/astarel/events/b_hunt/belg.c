inherit "obj/monster";

#include "/wizards/astarel/events/b_hunt/defines.h"


string *chat_str;

reset(arg) {
  ::reset(arg);
  if(arg) return;

    set_name("Belg");
    set_alias("master");
    set_short("Belg the legendary bunny-hunter.");
    set_long("apsdoa qy�08y!\n");
    set_level(100);
    set_al(0);
    set_alt_name("belg");
    
    chat_str = ({"Belg screams 'I hate bunnies! 'join' the hunt try catch them all!'\n",
                 "Belg mumbles 'Bunnies there, bunnies here, bunnies everywhere'\n",
                 "Belg wonders 'Sometimes i think i might be a little crazy.'n",
                 "Belg states 'I'm belg, i hunt bunnies, would you like to hunt bunnies too?'n",
                 "Belg shouts 'HUNT THE FUCKING BUNNIES!'\n",
		});       
        load_chat(1,chat_str);
}



ask_question(str) {
	if(str == "hunt") {
		say("Belg says 'yes yes yes! 'join' the bunnyhunt and lets catch'em all!\n");
		return 1;
	}
	
	return 1;
}


init() {
	::init();	
	add_action("join_hunt", "join");
}

status join_hunt() {
		
	BUNNY_D->add_bunnyhunter(lower_case(this_player()->query_name()));
	
return 1;
}
