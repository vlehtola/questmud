object victim;

get() { return 1; }

start(ob) { victim = ob; }

init() {
  add_action("cmd","cmd");
}

cmd(string arg) {
  if(!victim) destruct(this_object());
  if(!arg) return;
  if(arg == "quit") destruct(this_object());
  if(arg == "check") {
    write("Control_ob present.\n");
    return 1;
  }
  if(arg == "l" || arg == "look") victim->look();
  victim->init_command(arg);
}
