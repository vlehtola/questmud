inherit "room/room";
#include "/wizards/gheldor/include/event.h"
string *events;


reset(arg) {
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
   events = ({ "/wizards/gheldor/events/guglah/runner.c", });
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
  write("REPORT ALL BUGS TO GHELDOR!\n");
  ::long(wiz);
}

init() {
  ::init();
  add_action("run_stop","run");
  add_action("run_stop","stop");
  add_action("info_event","info");
}

status run_stop(int event) {
event++;
if(sizeof(events) < event || event <= 0) return 0;
  if(!event || !events[event] || call_other(events[event],"query_level") > this_player()->query_level()) {
    write("Error: Illegal event!\nPlease choose again.\n");
    return 1;
  }
  if(query_verb() == "stop" && call_other(events[event],"query_active") == "No") {
    write("But that event isn't running at the moment!\n");
    return 1;
  }
  if(query_verb() == "run" && call_other(events[event],"query_active") == "Yes") {
    write("But that event is running at the moment!\n");
    return 1;
  }
  write("You "+query_verb()+" the event!\n");
  call_other(events[event],query_verb()+"_event");
  write_file(LOGI,"["+ctime()+"] - "+this_player()->query_name()+" "+query_verb()+" event number ("+event+") ["+events[event]+"] !\n");
  return 1;
}

