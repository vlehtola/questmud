//This is the file for the treasure map -- Rag

//Minimap creates the long description
#define MINI "/wizards/rag/events/thunt/minimap"

//Master handles the event
#define MASTER "/wizards/rag/events/thunt/master"

//Too long to write many times
#define FIL file_name(environment(this_player()))

//The main file of the event
#define MAIN "/wizards/rag/events/thunt/start"

//Coordinates for the treasure
int x, y;

//Get the coordinates from the master npc
get_coords() {
        x = MASTER->get_x();
        y = MASTER->get_y();
        return 1;
}

//Actions for the map
init() {
        add_action("dig","dig");
        add_action("scores","scores");
}

//So, you want to dig the treasure
dig(str) {
        if(str != "treasure") return;
        write("You start digging.\n");
        say(this_player()->query_name()+" starts digging.\n");
        call_out("hep",3);
        return 1;
}

/* The digging takes time, here are the results.
   We need to update the coordinates so it won't bug.
   Also add scores to master npc			*/
hep() {
        get_coords();
        if(FIL->query_x() == x && FIL->query_y() == y) {
                write("You find the treasure!\n");
                say(this_player()->query_name()+" finds the treasure!\n");
                MASTER->add_score(this_player());
        } else {
                write("You don't find anything.\n");
                say(this_player()->query_name()+" doesn't find anything.\n");
        }
        return 1;
}

//Get the scores
scores() {
        MASTER->scores(this_player()->query_name());
        return 1;
}

//Yes, this is the map...
id(str) {
        return str == "map";
}

/* ...and it has a short desc, also destructs the map
   when the event is over. 				*/
short() { 
        if(!active()) {
                call_out("des",1);
        }
        return "A dusty old map";
}

/* The minimap handles the long_desc, also destructs
   the map when the event is over.			*/
long(str) {
        string long_desc;
        if(!active()) {
                call_out("des",1);
		return;
        }
        long_desc =     "\nThe legenday treasure hunt\n\n"+
                        "When you think that you have reached the\n"+
                        "treasure type 'dig treasure'\n"+
                        "Type 'scores' to see the scores.\n";
                        
        get_coords();
        write(MINI->generate_minimap(x,y,long_desc));
        return;
}

/* I wanted the map to be gettable and droppable.
   Still destructing the map.			*/
get(str) {
        if(!active()) {
                call_out("des",1);
                return 1;
        }
        return 1;
}

drop() {
        if(!active()) {
                call_out("des",1);
                return 0;
        }
        return 0;
}

//Noooo, the map crumples to dust!
des() {
        write("The event is over and the map crumples to dust.\n");
        destruct(this_object());
        return 1;
}

//We want to know if the event is active or not.
active() {
        if(MAIN->query_active() == "Yes") return 1;
        return 0;
}
