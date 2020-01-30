 reset(arg) {
  if(arg) return;
}
short() {
  return "the AVAIN";
}
alias() {
  return "avain0700123123";
}
id(str) {
  return str == "avain";
  /* we can also return str == name || str == fire || str == alt_name; etc */
}
long() {
  write("This is the avain.\n");
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

