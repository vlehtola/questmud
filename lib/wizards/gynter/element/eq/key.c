reset(arg) {
  if(arg) return;
}

id(str) {
 return str ==  "key";
}
short() {
  return "An old rusty key";
}
long() {
  write("This is a useless looking key, which is old and rusty. The are FL engraved\n");
  write("on it. It's a mystery, what those capital letters mean.\n");
}
query_weight() {
  return  1;
}
get() {
  return 1;
}
