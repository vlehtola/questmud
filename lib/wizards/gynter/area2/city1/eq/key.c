reset(arg) {
  if(arg) return;
}

id(str) {
 return str == "key";
}

short() {
  return "A small iron key";
}
long() {
  write("This is a small iron key. The key is covered with\n");
  write("small peices of old bread.");
}

query_weight() {
  return  1;
}

get() {
  return 1;
}