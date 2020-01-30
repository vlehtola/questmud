reset(arg) {
  if(arg) return;
}

id(str) {
  return str == "emerald";
}
short() {
  return "A glistering green emerald";
}
long() {
  write("This is a beautiful green emerald that once belonged\n"+
        "to the elementlord of water.\n");
}
query_weight() {
  return  1;
}
get() {
  return 1;
}
