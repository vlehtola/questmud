string desc;
reset(arg) {
  if(arg) return;
  desc = "This is a tiny patch of sheep wool.\n";
}


short() {
  return "A tiny patch of sheep wool";
}

id(str) {
  return str == "wool" || str == "patch" || str == "lampaan_villa";
}

long() {
  write(desc);
}
query_long() { return desc; }

drop() {
  return 0;
}

get() {
  return 1;
}

query_weight() {
  return 100;
}

