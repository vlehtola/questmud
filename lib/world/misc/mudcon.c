mapping list;

reset(arg) {
  if (!arg) { return; }
  restore_object("/obj/mudcon/save_file.o");
  if (!list) {
    list = ([ ]);
  }
}

short() { return "Mudcon sign up board"; }
long() {
write(
"You can sign up here if you are coming to the mudcon held 19.6 in\n"+
"Helsinki. See "help mudcon" for additional information.\n"+
"Commands: list\n"+
"          signup [additional info]\n"+
"Example:\n"+
"signup coming with train from oulu\n");
}

id(str) { if (str == "board") { return 1; } }

init() {
  add_action("list","list");
  add_action("signup","signup");
}

signup(str) {
  string name;
  name = this_player()->query_name();
  if (list[name]) { write("You already are signed up.\n");
  if (!str) { str = "coming"; }
  if (strlen(str) > 30) { write("Too long argument.\n");
  list[name] = str;
  write("You sign up.\n");

  save_file("/obj/mudcon/save_file.o");
  return 1;
}

list() {
  string names, args;
  names = m_indices(list);
  write("List of mudcon people:\n");
  while (i < sizeof(list)) {
    write(names[i]+", "+args[i]+"\n");
    i += 1;
  }
  return 1;
}
