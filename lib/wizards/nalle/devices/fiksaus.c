#include <ansi.h>

reset(arg) {
  if(arg) return;
}
 
init() {
  add_action("fiksaa", "fiksaa");
}
 
fiksaa(string str) {

if(!str) return 1;
write("Fiksing.\n");
present("horde", environment(this_player()))->add_undead(str);
return 1;
}

short() {
  return "fiksaus";
}
 

id(str) {
  return str == "fiksaus";
}
 
long() {
  write("fiksaa jotain\n");
}
 
drop() {
  return 0;
}
 

get() {
  return 1;
}
 

query_weight() {
  return 1;
}
