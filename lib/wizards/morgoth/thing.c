 reset(arg) {
  if(arg) return;
}

init() {
  add_action("expo", "expo");
}
 expo() {
 this_object()->add_experience(1000000);
 write("Something just happened.\n");
 return 1;
}

short() {
 return "Kapula";
 }
id(str) {
  return str == "kapula";
 }

long() {
  write("This is the kapula.\n");
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
