short() { return "writeob"; }
long() {
write("Try 'write'....\n");
}
id(str) { return str == "writeob"; }
init() {
  add_action("print", "write");
}
print(arg) {
  write_file("sumufile", arg);
  write(arg+"\n");
  return 1;
}





