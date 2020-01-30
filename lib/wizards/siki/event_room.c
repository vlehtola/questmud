inherit "room/room";
string *events;
int value;

reset(arg) {
  events = ({ "/wizards/gheldor/events/guglah/runner.c", "/wizards/siki/healer/start.c", "/wizards/siki/thunder/start.c", "/wizards/luminarc/spec/snow_start", });
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
  tmp = "+---------------------------------------------------------+\n";
 tmp += "| Num | Lvl  | Active | Creator    | Name                 |\n";
 tmp += "+-----+------+--------+------------+----------------------+\n";
  for(i=0;i<sizeof(events);i++) {
      tmp += sprintf("| %-3d | %-4d | %-6s | %-10s | %-20s |\n",
     i,
     call_other(events[i],"query_level"),
     (string)call_other(events[i],"query_active"),
     (string)call_other(events[i],"query_creator"),
     (string)call_other(events[i],"query_name"));
  }
 tmp += "+-----+------+--------+------------+----------------------+\n";
 tmp += "Made by Gheldor, modified by Neophyte\n";
 tmp += "Commands: run <event>, stop <event> info <event>\n";
 write(tmp);
  ::long(wiz);
}

init() {
  ::init();
  if(this_player() -> query_wiz() < 2) {
  write("You are not allowed to be here!\n");
  move_object(this_player(), "/world/city/cs");
  return;
}
  add_action("run_event","run");
  add_action("stop_event","stop");
  add_action("info_event","info");
}

run_event(str) {
	int event;
	if(!str) { write("Usage: run <event name>\n"); return 1; }
	event = get_event(str);
	if(event == -1) { write("No such event.\n"+ "Try: run [event name]\n"); return 1; }
	if(call_other(events[event], "query_active") == "Yes") {
		write("But that event is already running.\n");
		return 1;
	}
	write("Starting the event.\n");
	call_other(events[event], "run_event");
	log_file("EVENTS_RUN", ctime(time())+" Runner: "+this_player()->query_name()+" Event: "+str+"\n");
	return 1;
}
stop_event(str) {
	int event;
	if(!str) { write("Usage: stop <event name>\n"); return 1; }
	event = get_event(str);
	if(event == -1) { write("No such event.\n"+ "Try: stop <event name>\n"); return 1; }
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
	case "Healer":return 1;
	case "Thunderstorm":return 2;
	case "Snowfight":return 3;
}
return -1;
}
info_event(string str) {
	if(!str) { write("info <event name>\n"); return 1; }
	write("Displaying information of event "+str+".\n");
	write(get_info(str));
	return 1;
}

get_info(string word) {
	switch(word) {
		case "Guglah-Invasion":return call_other(events[0], "query_event_desc");
		case "Healer":return call_other(events[1], "query_event_desc");
		case "Thunderstorm":return call_other(events[2], "query_event_desc");
		case "Snowfight":return call_other(events[3], "query_event_desc");
	}
		return "No such event.\n";
}
