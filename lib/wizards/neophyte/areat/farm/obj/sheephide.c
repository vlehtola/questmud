string desc;
reset(arg) {
  if(arg) return;
  desc = "This hide is whie coloured and smells quite bad.\n";
}


short() {
  return "hide made from sheep";
}

id(str) {
  return str == "hide" || str == "sheephide" || str == "lampaan_talja";
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

