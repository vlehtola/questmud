#include <ansi.h>

#define SAVEFILE "/data/questcon"

string *osallistujat;

string short() {
  return "Questcon register board";
}

id(str) {
  return str == "board";
}

void long() {
  write("Available commands:\n"+
	"  register\n"+
	"  unregister\n"+
	"  list\n"+
	"See 'help mudcon' for additional info.\n");
}

void reset(status x) {
  if(x) return;
  osallistujat = ({ });
  if(!restore_object(SAVEFILE))
  	save_object(SAVEFILE);
}

void init() {
  add_action("check","list");
  add_action("register","register");
  add_action("unregister", "unregister");
}

unregister(string str) {
  int i;
  for(i=0; i < sizeof(osallistujat); i++) {
    if(this_player()->query_real_name() == osallistujat[i]) {
      osallistujat[i] = 0;
      write("You have been unregistered.\n");
      osallistujat = explode(implode(osallistujat, ","), ",");
      save_object(SAVEFILE);
      return 1;
    }
  }
  write("You are not registered.\n");
  return 1;
}

status register(string str) {
if(member_array(this_player()->query_real_name(),osallistujat) == -1) {
  write("You are now registered.\n");
  osallistujat += ({ this_player()->query_real_name(), });
  save_object(SAVEFILE);
  return 1;
} else { write("You are already registered.\n"); }

return 1;
}

status check() {
  int i;
  write("Signed in:\n");
  for(i=0;i<sizeof(osallistujat);i++) { write((1+i)+". "+capitalize(osallistujat[i])+"\n"); }
return 1;
}

status drop() { return 1; }
status give() { return 0; }
int query_weight() { return 1000000; }
