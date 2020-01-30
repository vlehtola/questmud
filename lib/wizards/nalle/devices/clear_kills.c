reset(arg) {
  if(arg) return;
}
 
init() {
  add_action("clearkills", "clearkills");
}
 
clearkills() {
write("Kills cleared.\n");
this_player()->clear_best_kills();
return 1;
}


short() {
  return "A kill clearing device";
}
 

id(str) {
  return str == "device";
}
 
long() {
  write("Damn this is cool, try 'clearkills'.\n");
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
