string desc;
reset(arg) {
  if(arg) return;
  desc = "A crystal with two small rubys embadded in.\n";
}


short() {
  return "A small crystal";
}

id(str) {
  return str == "crystal";
}

long() {
  write(desc);
}
query_long() { return desc; }
query_name() { return "crystal"; }

drop() {
  return 0;
}

get() {
  return 1;
}

query_weight() {
  return 500;
}

init() {
	add_action("throw_", "throw");
}
throw_(str) {
	object ob;
	if (present(this_object()) != this_player()) { write("Maybe you should pick it up first.\n"); return 1; }
	if(!str) { write("Throw at who?\n"); return 1; }
	ob = present(str, environment(this_player()));
	if(!ob) { write("There are no such thing here.\n"); return 1; }
	if(!function_exists("final_dest", ob)) { write("You could throw this at that, but without no affect.\n"); return 1; }
	write("You throw the crystal at ghost and it hits directly to the eye sockets.\n");
	say(this_player()->query_name()+" throws a crystal at ghost.\n");
	ob->final_dest();
	return 1;
}