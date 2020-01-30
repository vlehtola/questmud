 reset(arg) {
  if(arg) return;
}
short() {
  return "A small blue shard of a crystal";
}
id(str) {
  return str == "shard";
  /* we can also return str == name || str == fire || str == alt_name; etc */
}
long() {
  write("This is a small blue shard, from a crystal.\n");
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

