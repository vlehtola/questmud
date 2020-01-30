short() { return "A can of cola labeled 'codecola'"; }

long() {
  write("A can of cola\n");
  write("probably by Walla or Nalle.\n");
  }

get() { return 1; }


drop() { return 0; }

id(str) { return str == "cola"; }

init() {
  add_action("juo", "drink");
}

juo(str) {
  if(str != "cola" && str != "cola") { return; }
  write("mmmmm, goooood!!!!!!.\n");
  this_player()->drink_soft(21);
  destruct(this_object());
  return 1;
}
