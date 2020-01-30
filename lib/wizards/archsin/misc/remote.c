string where;

drop() { return 1; }
get() { return 1; }
long() { write("Remote controlling device.\n"); return 1; }
short() { return "Remote control"; }
id(str) { return (str == "remote"); }

portal(arg) {
  object ob, target;

  if(!arg) {
    write("What?\n");
    return 1;
  }

  if(!find_object(arg)) {
    write("Not valid object.\n");
    return 1;
  }
  call_other(arg, "???", 0);

  ob = clone_object("/wizards/archsin/misc/portal");
  ob->set_loc(arg);
  move_object(ob, environment(this_player()));

  target = clone_object("/wizards/archsin/misc/portal");
  target->set_loc(environment(this_player()));
  move_object(target, arg);
  write("Ok.\n");
  return 1;
}  

init() {
  add_action("portal", "portal");
}
