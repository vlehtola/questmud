reset(arg) {
  if(arg) return;
}
short() {
  return "A campfire";
}
id(str) {
  return str == "campfire";
  /* we can also return str == name || str == fire || str == alt_name; etc */
}
long() {
  write("A nice campfire warms the nearby place. It makes you feel more relaxed.\n");
}
drop() {
  return 1;
}
get() {
  return 0;
}
query_weight() {
  return 1000;
}
 
