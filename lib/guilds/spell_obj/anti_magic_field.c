short() {
  return "A shimmering purple force field";
}

long() {
  write("The force field glows purple light. It seems to draw all\n"+
        "other light coming from other sources to itself. The area\n"+
        "around it seems to somehow lose some of its freedom.\n"+
        "There is no doubt that this field is magical.\n");
}
id(str) { return str == "field" || str == "force field" || str == "amf"; }
query_amf() { return 1; }

start(time) {
  call_out("remove",time);
}

remove() {
  say("The force field vanishes.\n");
  destruct(this_object());
}

