inherit "room/room";
#define LOGI "/wizards/neophyte/event_log"
string *events;
int value;

hooveeerror tähän // remove this to compile

reset(arg) {
  events = ({ "/wizards/gheldor/events/guglah/runner.c", "/wizards/neophyte/blink/start.c", });
  if(arg) return;
  short_desc = "Event room";
  long_desc = "";
  property = ({ "no_summon", });
  set_light(10);
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
}

long(status wiz) {
string tmp;
  int i;
  write("No.     Level     Active     Name\n"+
        "----------------------------------------------------\n");
  for(i=0;i<sizeof(events);i++) {
      tmp = sprintf("%d     %d        %s          %s\n",
     i,
     call_other(events[i],"query_level"),
      (string)call_other(events[i],"query_active"),
       (string)call_other(events[i],"query_name"));
write(tmp);
  }
  write("Made by Gheldor, modified by Neophyte\n");
  write("Commands: run <event>, stop <event> info <event>\n");
  ::long(wiz);
}

init() {
  ::init();
  if(this_player() -> query_wiz() < 3) {
  write("You are not allowed to be here!\n");
  move_object(this_player(), "/world/city/cs");
}
  add_action("run_event","run");
  add_action("stop_event","stop");
  add_action("info_event","info");
}

run_event(str) {
	int event;
	if(!str) { write("Trying to run nothing.\n"); return 1; }
	event = get_event(str);
	if(call_other(events[event], "query_active") == "Yes") {
		write("But that event is already running.\n");
		return 1;
	}
	write("Starting the event.\n");
	call_other(events[event], "run_event");
	return 1;
}
stop_event(str) {
	int event;
	if(!str) { write("Trying to stop nothing.\n"); return 1; }
	event = get_event(str);
	if(call_other(events[event], "query_active") == "No") {
		write("But that event is not running.\n");
		return 1;
	}
	write("Stopping the event.\n");
	call_other(events[event], "end_event");
	return 1;
}

get_event(int i) {
	switch(i) {
	case "Guglah-Invasion":return 0;
	case "Hunt the blink dog":return 1;
}
return -1;
}
info_event(string str) {
	if(!str) { write("Info event name.\n"); return 1; }
	write("Displaying information of event "+str+".\n");
	write(get_info(str));
	return 1;
}

get_info(string word) {
	switch(word) {
		case "Guglah-Invasion":return call_other("/wizards/gheldor/events/guglah/runner.c", "query_event_desc");
		case "Hunt the blink dog":return call_other("/wizards/neophyte/blink/start.c", "query_event_desc");
	}
			return "No such event.";
}
