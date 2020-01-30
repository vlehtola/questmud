//New events-command, Rag
//Takes events directly from the event room from /room/event_room
#define EVENT_D "/room/event_room"

cmd_events(str) {
        string *events;
        int event_n, i, j, n;
        events = EVENT_D->query_events();
        event_n = sizeof(events);

        if(!str) {
                write("Available events in QuestMUD:\n\n");
                for(i = 0;i < event_n;i++) {
                        j = i+1;
                        write(j+". "+events[i]->query_name()+"\n");
                }
                write("\nType 'events <name/number>' to see info about the event.\n");
                return 1;
        } else if(str) {
                n = EVENT_D->get_event_number(str);
                if(n == -1) {
                        write("No such event, try 'events'\n");
                        return 1;
                }
                write("Event name: "+events[n]->query_name()+"\n");
                write("   Creator: "+events[n]->query_creator()+"\n\n");
                write("Description:\n"+events[n]->query_mortal_desc()+"\n");
                if(this_player()->query_wiz()) {
                        write("Wiz_desc:\n"+events[n]->query_event_desc()+"\n");
                        if(events[n]->not_run_with()) {
                         write("This event cannot be run with "+
                         events[n]->not_run_with()->query_name()+".\n");
                        }
                }
                return 1;
        }       
}
