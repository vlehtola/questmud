int used = 5;

reset(arg) { if(arg) { return; } }
id(str) { return str == "flagon";  }

get() { return 1; }

short() {
  if(used == 3) {  return "An empty flagon";  }
  if(used == 2) {  return "A half-full flagon";  }
  if(used == 1) {  return "An almost empty flagon";  }
  if(used == 0) {  return "And empty flagon";  }
}

long(str) {
 if(used == 0) {
  write("An empty flagon. It is a useful item if you want to carry some water with you.\n");
 }
 if(used == 1) {
  write("The flagon is almost empty. It is a useful item if you want to carry some\n"+
        "water with you.\n");
 }
 if(used == 2) {
  write("The flagon is half-full. It is a useful item if you want to carry some\n"+
        "water with you.\n");
 }
 if(used == 3) {
  write("A full flagon. It is a useful item if you want to carry some\n"+
        "water with you.\n");
 }
