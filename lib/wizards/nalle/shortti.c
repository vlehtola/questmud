#include <ansi.h>

reset(arg) {
  if(arg) return;
}
 
init() {
  add_action("shortti", "shortti");
}
 
shortti() {
string str;

write("Pok.\n");
str = RED_F+"Nalle"+OFF;
this_player()->set_wiz_short(str);
return 1;
}

short() {
  return "punanen jutska";
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
