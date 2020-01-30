string short;

reset(arg) {
  if(arg) return;
  short = "A limb (report that you have seen this)";
  call_out("rot", 30+random(60));
}
id(str) {
  string tmp,tmp2;
  if(str == "limb") return 1;
  if(sscanf(short, "%s"+str+"%s",tmp,tmp2) == 2) {
    if(str == "head") return 1;
    if(str == "arm") return 1;
    if(str == "leg") return 1;
  }
}

rot() {
  short = "Rotting remains of "+short;
  call_out("dump", 20+random(50));
}

dump() {
  destruct(this_object());
}

set_short(str) { short = str; }

short() { return short; }
long() {
  write(short+" has been cut off from some poor creature. It's really bloody\n"+
	"and not agreable to touch. Yuch!\n");
}

