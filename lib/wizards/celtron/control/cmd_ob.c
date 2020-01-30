init() {
  add_action("kill", "kill");
  add_action("take", "take");
  add_action("look", "l");
  add_action("look", "look");
  add_action("move", "s");
  add_action("move", "n");
  add_action("move", "w");
  add_action("move", "e");
}
move() {
  string s;
  s = query_verb();
  if(s=="s") s = "south";
  if(s=="n") s = "north";
  if(s=="w") s = "west";
  if(s=="e") s = "east";
  this_player()->init_command(s);
  return 1;
}

kill(arg) {
  object ob;
  if(arg && ob = present(arg, environment(environment())) && living(ob)) {
	write("killing..\n");
	this_player()->attack_object(ob);
	return 1;
  }
  write("Unable to kill.\n");
  return 1;
}

take(arg) {
  object ob;
  if(arg && ob = present(arg, environment(this_player())) && ob->get()) {
    move_object(ob,this_player());
    tell_room(environment(this_player()), this_player()->short()+" takes "+ob->short()+".\n");
    return 1;
  }
  write("Unable to take.\n");
  return 1;
}

look() {
  this_player()->look();
  return 1;
}

south() {
  this_player()->init_command("south");
  return 1;
}

