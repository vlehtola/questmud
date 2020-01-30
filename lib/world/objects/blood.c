int i;
string short;
reset(arg) {
  if(arg) return;
  i = random(4);
  if(i==0) set_short("A huge pool of blood covering the ground");
  if(i==1) set_short("Some blood drops lying on the ground");
  if(i==2) set_short("A little pool of blood covers ground");
  if(i==3) set_short("A small amount of blood lying on the ground");
  call_out("dry", 120+random(120));
}

set_short(str) { short = str; }
short() { return short; }
id(str) { return str == "blood" || str == "pool" || str == "drops" || str== short; }

long() {
  write("Blood is fresh and propably from some creature that is nearby.\n"
        "The red liquid looks disgusting.\n");
}

dry() {
  destruct(this_object());
}

query_blood() {
        return this_object();
}

query_level() {
        return 10-i;
}
