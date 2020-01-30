object victim,controller,ob;
string name;
int weight;

reset(arg) {
  if (arg) { return; }
  name = "device"; weight = 1;
}

query_weight() { return weight; }

init() {
  add_action("start", "control");
}

get() { return 1; }

start(str) {
  if (sscanf(str, "%s", name) != 1) {
    write("Usage: control <name>\n");
    return 1;
  }
  victim = present(name, environment(this_player()));
  controller = this_player();
  ob = clone_object("/players/celtron/controlob");
  move_object(ob, victim);
  ob->start(victim, controller);
  if (interactive(victim)) { remove_interactive(victim); }
  exec(victim, controller);
  remove_interactive(controller);
  write("You are now controlling "+name+".\n");
  input_to("give_order");
  return 1;
}

id(str) { return name == str; }
short() { return "A mind control device"; }
long() {
  write("This mystic object is made for controlling others minds.\n");
}

give_order(str) {
  if(str == "**") {
    stop();
    return 1;
  }
  if (str) { victim->party_move(str); }
  input_to("give_order");
}

stop() {
  write("The mental connection breaks.\n");
  exec(controller, victim);
  destruct(ob);
  return 1;
}
