reset(arg) {
  if(arg) return;
}

id(str) {
 return str ==  "pouch";
}
short() {
  return "A pouch";
}
long() {
  write("This is a dust pouch.\n");
}
query_weight() {
  return  1;
}
get() {
  return 1;
}
