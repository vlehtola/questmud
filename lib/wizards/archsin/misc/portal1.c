string where;

drop() { return 1; }
get() { return 0; }
long() { write("Dim portal.\n"); return 1; }
short() { return "Dim portal"; }
id(str) { return (str == "portal"); }

query_loc() {
  return where;
}

set_loc(arg) {
  where = arg;
}

enter(arg) {
  object ob, env;

  if(!arg) return;
  if(arg == "portal") {

    if(!where) {
      write("Portal stays dim.\n");
      return 1;
    }
    move_object(this_player(), where);
    write("You feel dizzy.\n");
    say(this_player()->query_name()+" vanishes through portal.\n");
  }
  else {
    write("What?\n");
  }
  return 1;
}

init() {
  add_action("enter", "enter");
}
