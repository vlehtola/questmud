cmd_fenter(obj) {
  object ob;
  if(!obj) {
    write("Usage: fenter <object>\n");
    return 1;
  }
  ob = present(obj,environment(this_player()));
  if(!ob) {
    write("No "+obj+" here.\n");
    return 1;
  }
  write("You enter "+obj+".\n");
  move_object(this_player(), ob);
  return 1;
}

