cmd_fleave(obj) {
  object ob;
  ob = environment(this_player());
  if(!ob) {
    write("No environment found.\n");
    return 1;
  }
  if(!environment(ob)) {
    write("No destination.\n");
    return 1;
  }
  write("You leave "+ob->short()+".\n");
  move_object(this_player(), environment(ob));
  return 1;
}

