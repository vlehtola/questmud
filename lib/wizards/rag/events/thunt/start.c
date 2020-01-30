/* The master file that all events need */

//This events has the master object NPC to handle thing
object master;

//1 = active, 0 not active
int run;

//The name of the event
query_name() { return "Treasure hunt"; }

//Yes, I made this one :)
string query_creator() { return "Rag"; }

//Description for wizards
string query_event_desc() { return
"Hoxbah the gnome has arrived to organize the\n"+
"legendary treasure hunt. You can find him at\n"+
"the Central Square. The winner gets silver\n"+
"coins and a quest woth 4 QPs.\n";}

//Description for mortals
string query_mortal_desc() { return
"Hoxbah the gnome has arrived to organize the\n"+
"legendary treasure hunt. You can find him at\n"+
"the Central Square.\n";}

//Apprentice wizards can't run this event, code areas!
int query_limit() { return 2; }

/* Yes and No, basicly not a nice way to code
   but it was there already                     */
string query_active() {
        if(run) return "Yes";
        return "No";
}

//What happens when someone runs the event
void run_event() {
        run = 1;
        master = clone_object("/wizards/rag/events/thunt/master");
        move_object(master, "/world/city/cs");
        tell_room("/world/city/cs", "Hoxbah the gnome arrives!\n");
        shout("Hoxbah the gnome has arrived to the Central Square!\n");
        shout("Contact him if you want to participate in the Treasure Hunt!\n");
        return;
}

//What happens when the event is over or someone ends it
void end_event() {
        run = 0;
        if(master) {
                tell_room(environment(master),"Hoxbah waves happily and starts wandering south.\n");
                destruct(master);
        }
        shout("The treasure hunt is over!\n");
        return;
}

special() {
        int x, y;
        if ( run && master ) {
                x = master->get_x();
                y = master->get_y();
                this_player()->move_player("X#virtual /room/out/outmap "+x+" "+y);
        } else {
                write("Event is not active or it is bugging.\n");
        }
}
