 reset(arg) {
  if(arg) return;
}
short() {
  return "A shopping cart, labeled Reg Rubseh";
}
id(str) {
  return str == "cart";
  /* we can also return str == name || str == fire || str == alt_name; etc */
}
long() {
  write("This is a shopping cart, owned by Reg Rubseh.\n");
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
