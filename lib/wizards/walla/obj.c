reset(arg) {
  if(arg) return;
}
 
init() {
  add_action("do_something", "ojees");
}
 
do_something() {
  this_player()->death();
}
 
short() {
  return "Alright, this object has a short";
}
 

id(str) {
  return str == "object";
}
 
long() {
  write("This is the LONG desc.\n");
}
 
drop() {
  return 0;
}
 

get() {
  return 1;
}
 

query_weight() {
  return 10;
}
