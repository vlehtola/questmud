cmd_fdrop(obj) {
  object ob;
  ob = present(obj, this_player());
  if(!ob) {
    write("You don't have any "+obj+".\n");
    return 1;
  }
  write("You drop "+ob->short()+".\n");
  say(this_player()->query_name()+" drops "+ob->short()+".\n");
  move_object(ob,environment(this_player()));
  this_player()->fix_weight();
  return 1;
}

