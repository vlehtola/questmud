short() {
  return "A glowing yellow force field is surrounding this area";
}

long() {
  write("The force field is translucent, everything beyond it seems\n"+
        "yellow. It seems very thin and fragile, yet it's magical\n"+
        "and can contain some weird and insidious capabilities.\n"+
        "One cannot leave this place by not trying to go through it.\n");
}

id(str) { return str == "field" || str == "force field" || str == "shelter"; }
query_shelter() { return 1; }

start(time) {
  call_out("remove",time);
}

remove() {
  say("The force field vanishes.\n");
  destruct(this_object());
}
