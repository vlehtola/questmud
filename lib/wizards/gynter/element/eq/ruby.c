reset(arg) {
  if(arg) return;
}

id(str) {
  return str == "ruby";
}
short() {
  return "A fire-red ruby";
}
long() {
  write("This is a red ruby large as a fist. It has a small light\n"+
        "inside of it. Almost as if there is a flame inside.\n");
}
query_weight() {
  return  1;
}
get() {
  return 1;
}
