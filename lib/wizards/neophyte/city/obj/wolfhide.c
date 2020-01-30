reset(arg) {
  if(arg) return;
}


short() {
  return "hide made from wolf";
}

id(str) {
  return str == "hide" || str == "wolfhide" || str == "suden_talja";
}

long() {
  write("This marvelous wolfhide is silver coloured.\n");
}

drop() {
  return 0;
}

get() {
  return 1;
}

query_weight() {
  return 15;
}

