#include <ansi.h>

reset(arg) {
  if(arg) return;
}
 
init() {
  add_action("shortti", "shortti");
}
 
shortti(string str) {

if(!str) return 1;
write("Pok.\n");
find_player("ozmala")->set_wiz_short(str);
return 1;
}

short() {
  return "jutska";
}
 

id(str) {
  return str == "jutska";
}
 
long() {
  write("pah\n");
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
