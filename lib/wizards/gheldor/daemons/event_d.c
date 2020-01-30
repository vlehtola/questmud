#include "/wizards/gheldor/include/event.h"

string *events;

void reset(status arg) {
  if(arg) return;

events = ({ "/wizards/gheldor/events/guglah/runner", });
restore_object(SAVE);
}

void add_event(string fname) {
  string error;
  if(this_player()->query_wiz() < 3 && this_player()->query_name() != "Gheldor") {
    write_file(LOGI,"["+ctime()+"] - "+this_player()->query_name()+" ("+this_player()->query_wiz()+")tried to add event "+fname+"!\n");
    return;
  }
  if(file_size(fname) < 10 || error = catch(call_other(fname,"???"))) {
    write("EVENT_D ERROR!\n");
    write("-> "+error+"\n");
    write_file(LOGI,"["+ctime()+"] - "+this_player()->query_name()+" got from "+fname+":\n"+error+"\n");
    return;
  }
  events += ({ fname, });
  write_file(LOGI,"["+ctime()+"] - "+this_player()->query_name()+" ("+this_player()->query_wiz()+") added event "+fname+"!\n");
  save_object(SAVE);
  return;
}

void remove_event(string fname) {
  if(this_player()->query_wiz() < 3 && this_player()->query_name() != "Gheldor") {
    write_file(LOGI,"["+ctime()+"] - "+this_player()->query_name()+" ("+this_player()->query_wiz()+")tried to add event "+fname+"!\n");
    return;
  }
  if(!member_array(fname,events)) {
    write("There is no such event!\n");
    return;
  }
  events -= ({ fname, });
  write_file(LOGI,"["+ctime()+"] - "+this_player()->query_name()+" ("+this_player()->query_wiz()+") removed event "+fname+"!\n");
  save_object(SAVE);
  return;
}

string *query_events() { return events; }
