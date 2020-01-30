reset(arg) { 
  if(arg) return;
}
short() {
  return "A transparent glasseye";
}
id(str) {
  return str == "glasseye";
}
long() {
  write("This is a glasseye. You wonder to whom it might belong.\n");
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
