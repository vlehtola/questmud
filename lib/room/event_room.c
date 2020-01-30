inherit "room/room";
string *events;
int event_amount;

reset(arg) {
  events = ({   "/wizards/gheldor/events/guglah/runner",
                "/wizards/siki/healer/start.c",
                "/wizards/siki/thunder/start.c",
                //"/wizards/luminarc/spec/snow_start",
                //Snowfight is disabled, it doesn't work
                "/wizards/rag/events/thunt/start",
                "/wizards/jenny/events/robbers/runner",
                "/wizards/rag/events/teleport/start" });
  event_amount = sizeof(events);
  if(arg) return;
  short_desc = "Event room";
  long_desc = "";
  property = ({ "no_summon", });
  set_light(10);
  add_exit("inn","/world/city/inn");
  add_exit("job","/room/job_room");
  add_exit("wizg","/world/city/innstabl");
  add_exit("cs","/world/city/cs");
}

long(status wiz) {
string tmp;
  int i;
  tmp = "+----------------------------------------------------------+\n";
 tmp += "| Num | Limit | Active | Creator    | Name                 |\n";
 tmp += "+-----+-------+--------+------------+----------------------+\n";
  for(i=0;i<event_amount;i++) {
      tmp += sprintf("| %-3d | %-5d | %-6s | %-10s | %-20s |\n",
     i+1,
     events[i]->query_limit(),
     (string)events[i]->query_active(),
     (string)events[i]->query_creator(),
     (string)events[i]->query_name());
  }
 tmp += "+-----+-------+--------+------------+----------------------+\n";
 tmp += "Made by Gheldor, modified by Neophyte, tweaked by Rag\n";
 tmp += "Commands:\nrun <name/number>, stop <name/number>, info <name/number>\n";
 write(tmp);
  ::long(wiz);
}

init() {
  ::init();
  add_action("run_event","run");
  add_action("stop_event","stop");
  add_action("info_event","info");
  add_action("special","special");
}

run_event(str) {
        int i, n;
        if(!str) { write("Usage: run <event name/number>\n"); return 1; }

        n = get_event_number(str);
        
        if(n == -1) {
                write("No such event.\n");
                return 1;
        }
        
        //Most events have some restrictions but you can always run your own event
        if(events[n]->query_limit() > this_player()->query_wiz() && events[n]->query_creator() != this_player()->query_name()) {
                write("You don't have the rights to run this event.\n");
                return 1;
        }
        
        if(capitalize(events[n]->query_active()) == "Yes") {
                write("But that event is already running.\n");
                return 1;
        }

        if(events[n]->not_run_with()) {
         if(capitalize(events[n]->not_run_with()->query_active()) == "Yes") {
                write("This event cannot be run if "+events[n]->not_run_with()->query_name()+" is active\n");
                return 1;
         }
        }

        write("Starting event "+events[n]->query_name()+"\n");
        events[n]->run_event();
        log_file("EVENTS_RUN", ctime(time())+" Runner: "+this_player()->query_name()+" Event: "+events[n]->query_name()+"\n");
        return 1;
}
stop_event(str) {
        int n;
        if(!str) { write("Usage: stop <event name/number>\n"); return 1; }
        
        n = get_event_number(str);
        
        if(n == -1) { write("No such event.\n"); return 1; }
        
        if(capitalize(events[n]->query_active()) == "No") {
                write("But that event is not running.\n");
                return 1;
        }
        write("Stopping event "+events[n]->query_name()+"\n");
        events[n]->end_event();
        return 1;
}

info_event(string str) {
        int n;
        if(!str) { write("info <event name/number>\n"); return 1; }
        
        n = get_event_number(str);
        
        if(n == -1) { write("No such event.\n"); return 1; }
        
        write("Displaying information of event "+events[n]->query_name()+".\n");
        write(events[n]->query_event_desc());
        if(events[n]->not_run_with()) {
                write("This event cannot be run with "+events[n]->not_run_with()->query_name()+".\n");
        }
        return 1;
}

special(string str) {
        int n;
        if(!str) { write("info <event name/number>\n"); return 1; }

        n = get_event_number(str);

        if(n == -1) { write("No such event.\n"); return 1; }

        events[n]->special();
        return 1;
}

get_event_number(str) {
        int i;
        if(strlen(str) < 3)
                str = to_int(str);
        if(intp(str)) {
                if(str < 1 || str > event_amount) {
                        return -1;
                }
                return str-1;
        } else {
                for(i = 0;i<event_amount;i++) {
                        if(lower_case(str) == lower_case(events[i]->query_name())) {
                                return i;
                        }
                }
        }
        return -1;
}

query_events() { return events; }
