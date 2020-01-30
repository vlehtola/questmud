 reset(arg) {
  if(arg) return;
}
short() {
  return "A small hat, filled with money";
}
id(str) {
  return str == "hat";
  /* we can also return str == name || str == fire || str == alt_name; etc */
}
long() {
  write("This is a small grey hat, to which people can 'donate' money.\n");
}
drop() {
  return 1;
}
get() {
  return 0;
}
query_weight() {
  return 1;
}
