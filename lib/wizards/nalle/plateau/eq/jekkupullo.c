short() { return "A bottle of herbal liquor"; }

long() {
  write("A bottle of herbal liquor, made in a far away place.\n");
  }

get() { return 1; }

drop() { return 0; }

id(str) { 
if (str == "bottle" || str == "jekkupullo" || str =="liquor") return 1; 
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

