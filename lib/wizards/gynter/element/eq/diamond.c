reset(arg) {
  if(arg) return;
}

id(str) {
  return str == "diamond";
}
short() {
  return "A clean-cut beautiful diamond";
}
long() {
  write("This is a priceless diamond.\n"+
        "There exists only a few of its kind in the world.\n"+
        "This once belonged to the elemental lord of the earthrealm.\n");
}
query_weight() {
  return  1;
}
get() {
  return 1;
}
