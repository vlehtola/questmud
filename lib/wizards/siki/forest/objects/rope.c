short() {
  return "A bloody rope";
}
id(str) {
  return str == "rope";
}

long() {
 write("A quite long piece of rope. The rope is\n"+
       "covered with blood. It is made of hemp.\n");
}
drop() {
  return 0;
}
get() {
  return 1;
}
reset(arg) {
  if(arg) return;
}
query_weight() { return 300; }

query_no_save() { return 1; }
