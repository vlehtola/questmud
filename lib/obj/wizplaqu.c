short() {
   return "A platinum plaque hanging on the wall";
}

long() {
   write("This plaque contains the names of most active coders.\n");
   write("Type 'list' to see the coder scores.\n");
}

id(str) { return str == "plaque"; }

init() {
   add_action("list", "list");
}

list() {
  if (!call_other(find_object("obj/wizlist"), "list")) {
      write("No one has yet been awarded for anything.\n");
  }
  return 1;
}
