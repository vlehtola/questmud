reset(arg) {
  if(arg) return;
}

short() {
  return "A tinkling sack full of something";
}

id(str) {
  return str == "sack";
}

long() {
  write("A brown sack full of something that tinkles loudly when the sack is\n" + 
        "moved. Maybe the sack is full of money. You should open and see what\n" + 
        "is inside. This item has been summoned with a weak magic wand.\n");
}

get() {
  return 1;
}

query_weight() {
  return 500;
}

init() {
  add_action("hep", "open");
}

hep(str) {
  if(str == "sack") {
    write("You open the brown sack and discover what is inside: The sack is full\n" + 
          "of bottlecaps and buttons! Suddenly you become extremely frustrated and\n" + 
          "throw the open sack on the ground with all your strength. The sack flies\n" + 
          "right through the ground and you lost it from your sight.\n");
    destruct(this_object());
    return 1;
  }
  else {
    return;
  }
}
