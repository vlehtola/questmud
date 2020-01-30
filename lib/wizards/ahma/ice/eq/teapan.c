int drank;

reset(arg) {
  if(arg) return;
}

short() {
  return "A brass tea pan";
}

id(str) {
  return str == "pan";
}

long() {
  write("A brass tea pan is almost shiny and few carvings decorate its, otherwise,\n" +
        "pale surface. It emits a weak, fascinating scent and there seems to be\n" +
        "some special liquid in it.\n");
}

long2() {
  write("A brass tea pan is almost shiny and few carvings decorate its, otherwise,\n" +
        "pale surface. It emits very weak, fascinating scent, but it seems to be\n" +
        "empty.\n");
}

get() {
  return 1;
}

query_weight() {
  return 60;
}

status query_empty() {
  return drank;
}

void init() {
  add_action("drink", "drink");
}

drink(str) {
  if(str == "from pan" || str == "liquid") {
    if(drank) {
      write("The tea pan is empty.\n");
      return 1;
    }
    write("You drink all the liquid from the tea pan and feel refreshed.\n");
    say(this_player()->query_name() + " drinks the liquid from the tea pan.\n");
    drank = 1;
    long2();
    return 1;
  }
  return;
}