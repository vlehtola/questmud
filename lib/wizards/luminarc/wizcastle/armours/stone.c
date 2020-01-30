reset(arg) {
  if(arg) return;
}
id(str) {
  return str == "soulstone" || str == "anti-illusion-stone";
}
get() {
  return 1;
}
query_weight() {
  return 100;
}
short() {
  return "Black soulstone";
}
long() {
  write("This stone is made from black stone. you can hear whispers inside of it.\n");
}

