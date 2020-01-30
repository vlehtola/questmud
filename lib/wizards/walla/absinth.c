short() { return "A bottle of absinth"; }

long() {
  write("A bottle of absinth\n");
  write("probably by Walla or Nalle.\n");
  }

get() { return 1; }

drop() { return 0; }

id(str) { return str == "absinth"; }

init() {
  add_action("juo", "drink");
}

juo(str) {
  if(str != "absinth" && str != "absinth") { return; }
  write("FUCK, jesus christ, that was the worst shit ever.\n");
  this_player()->drink_soft(10000);
  this_player()->set_hp(1);
  this_player()->set_sp(0);
  this_player()->set_ep(0);
  destruct(this_object());
  return 1;
}

