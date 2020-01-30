short() { return "A bottle of liquorice liquor"; }

long() {
  write("A bottle of liquorice liquor, made in a far away place.\n");
  }

get() { return 1; }

drop() { return 0; }

id(str) { 
if (str == "bottle" || str == "salmaripullo" || str =="liquor") return 1; 
}

init() {
  add_action("juo", "drink");
}

juo(str) {
  if(str != "liquor") { return; }
  write("Aah, that feels good.\n");
  this_player()->drink_soft(1000);
  destruct(this_object());
  return 1;
}

