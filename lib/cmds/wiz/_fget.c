cmd_fget(obj) {
  object ob;
  ob = present(obj, environment(this_player()));
  if(!ob) {
    write("You don't see a "+obj+".\n");
    return 1;
  }
  write("You take "+ob->short()+".\n");
  say(this_player()->query_name()+" takes "+ob->short()+".\n");
  move_object(ob,this_player());
  this_player()->fix_weight();
  return 1;
}

