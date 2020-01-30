string short;
start(int l, int t) {
  short = "A ball of light";
  if (l < 0) { short = "A ball of darkness"; }
  set_light(l);
  call_out("time_out", t, l);
}

short() { return short; }

get() { return 1; }

id(str) { if (str == "ball") { return 1; } }

time_out(l) {
  set_light(-l);
  destruct(this_object());
  if (l > 0) {
    say("The ball of light vanishes.\n");
  } else {
    say("The ball of darkeness vanishes.\n");
  }
}
