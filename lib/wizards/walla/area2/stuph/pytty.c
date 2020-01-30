 reset(arg) {
  if(arg) return;
}
short() {
  return "A huge cauldron";
}
id(str) {
  return str == "cauldron";
  /* we can also return str == name || str == fire || str == alt_name; etc */
}
long() {
  write("A huge cauldron burns, with eternal fire\n");
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
