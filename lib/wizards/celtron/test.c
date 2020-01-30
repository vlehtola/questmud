long() { write(short()); }
short() { return "test"; }
id(str) { str == "test"; }
init() {
  add_action("do_test", "test");
}

do_test(string p) {
int i;
sscanf(p, "%d", i);
write("Callout "+i+"\n");
call_out("end_test", i);
  return 1;
}
 
end_test() {
  write("end_test\n");

}
