object monsu;

id(str) { return str == "orb"; }
short() { return "Orb of controlling"; }
long() {
  write("Try: control\n");
}
init() {
  add_action("control", "control");
}
get() {
  if(!this_player()->query_wiz()) destruct(this_object());
  return 1;
}
control(arg) {
  object ob,ob2,tmp;
  if(!this_player()->query_wiz()) destruct(this_object());
  if(!arg) return;
  ob = present(arg, environment(this_player()));
  if(!ob) return;
  write("controlling..\n");
  ob2 = this_player();
  tell_object(ob, "YOU ARE A MONSTER!\n");
  if(ob2) tell_object(ob2, "YOU ARE THE PLAYER!\n");
  move_object(clone_object("/wizards/celtron/control/cmd_ob"),ob);
  clone_object("/wizards/celtron/control/shadow")->start(ob,ob2);
  tell_object(ob2, "nyt lahtee.. muista syntax: cmd <command>\n");
  tmp = clone_object("/wizards/celtron/control/control_ob");
  tmp->start(ob);
  move_object(tmp,ob2);
  monsu = ob;
  input_to("komento");
  return 1;
}

komento(string arg) {
  if(arg == "**") return 1;
  monsu->init_command(arg);
  input_to("komento");
  return 1;
}
