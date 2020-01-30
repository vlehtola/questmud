int a;
mixed *b;

get() { return 1; }
short() { return "test"; }
id(str) { return (str == "test"); }

reset(arg) {
  if(arg) return;
  a = 4;
  b = ({
    ({ 1, 2, "room", "#", }),
    ({ 1, 2, "room", "#", }),
    ({ 1, 2, "room", "#", }),
    ({ 1, 2, "room", "#", }),
      });
  //  add_it();
}

add_it() {
  b += ({ 2, 3, "room2", "?", });
  a++;
}

write() {
  int i;
  for(i=0; i<a; i++) {
    write(i+": "+b[0][0]+"\n");
  }
}

init() {
  add_action("add_it", "addit");
  add_action("write", "write");
}
