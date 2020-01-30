#include "ansi.h"
inherit "room/room";

init() {
        add_action("enter","enter");
        ::init();
}

reset(arg) {
        if(arg) return;
        add_exit("north","/wizards/rag/ruins/church4");
        add_exit("south","/wizards/rag/ruins/church1");

        short_desc = "Main hall of the church";
        long_desc =     "This once glorious church has been defiled by an unholy force. Everything\n"+
			"has been burned or smashed to pieces. Quite a few skeletons are scattered\n"
			"around the hall. The ceiling and the walls are blackened by fire. The floor\n"+
			"looks very dangerous because most of the wooden planks are badly charred.\n"+
			"Tall windows rise on the western and the eastern walls but they are all\n"+
			"smashed. There are some old bloodstains all over the hall.\n";

        set_not_out(1);        
        items = allocate(4);
        items[0] = "skeletons";
        items[1] = "These poor people must have died when church was rampaged";
        items[2] = "windows";
        items[3] = "You see gothic-styled windows without glasses";

        set_sound(23+random(6),"You hear the pouring rain and the raging thunder.\n");
}

enter(str) {
        if(str == "portal" && present("portal123")) {
                write("You take a deep breath and enter the portal fearlessly.\n");
                say(this_player()->query_name()+" takes a deep breath and enters the portal fearlessly.\n");
                this_player()->move_player("portal#/wizards/rag/ruins/junction");
                return 1;
        } else if(str == "portal") {
                write("What portal?\n");
                return 1;
        } else {
                write("Enter what?\n");
                return 1;
        }
}

chant(str) {
        string tmp,tmp2;
        if(str == "porta" && !present("portal123")) {
        	if(this_player()->query_terminal()) {
                	tell_room(this_object(),"The scroll flashes "+BOLD+WHITE_F+"brightly"+OFF+" and suddenly a magical "+
                	"portal appears in a "+BOLD+RED_F+"flash"+OFF+".\n");
                } else {
                	tell_room(this_object(),"The scroll flashes brightly and suddenly a magical "+
                	"portal appears in a flash.\n");
                }
                move_object(clone_object("/wizards/rag/ruins/obj/portal"),this_object());
        } else if(str == "porta" && present("portal123")) {
        	if(this_player()->query_terminal()) {
                	tell_room(this_object(),"The scroll flashes "+BOLD+WHITE_F+"brightly"+OFF+" and the portal glows "+
                	BOLD+RED_F+"red"+OFF+" for a while.\n");
                } else {
                	tell_room(this_object(),"The scroll flashes brightly and the portal glows "+
                	"red for a while.\n");
                }
        }
        return 1;
}
