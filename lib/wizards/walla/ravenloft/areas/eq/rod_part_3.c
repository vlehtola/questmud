reset(arg) { 
  if(arg) return;
}
 init() {
  add_action("smirk", "ojees");
}
 do_something() {
  this_player()->death();
}
 short() {
  return "Rod of 7 parts, part 3";
}
 id(str) {
  return str == "rod";
}
 long() {
  write("One of the parts to the rod of 7 parts. If you had them all, you could maybe do something.\n");
}
 drop() {
  return 1;
}
 get() {
  return 1;
}
 query_weight() {
  return 2;
}
