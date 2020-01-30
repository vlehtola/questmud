reset(arg) {
  if(arg) return;
}

short() {
  return "A healthy-looking violet";
}

id(str) {
  return str == "violet";
}

realid(str) {
  return str == "real";
}

long() {
  write("A small violet looks very healthy. It must have been treated and taken care\n" + 
        "of very well before it was picked from the ground. Seems almost like its\n" + 
        "petals would have been trimmed to make its outlook even better. The violet\n" + 
        "is emitting a gentle scent.\n");
}

get() {
  return 1;
}

query_weight() {
  return 1;
}
