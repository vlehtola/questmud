cmd_ndrink(string str) {
  object ob;
  object room;
  string what;
  if (!this_player()->check_condis()) { return 1; }
  if(!str) { write("drink what?\n"); return 1; }
  ob = present(str, this_player());
  room = environment(this_player());
  if(!ob)ob=present(str, environment(this_player()));
  if(!ob)ob=room;
  if(!ob->query_can_drink()) {
  write("You can't drink from that.\n");
  return 1;
}
  what = ob->query_drink_source();
  if(!what)what = "something";
  write("You drink "+what+" from the "+str+".\n");
  say(this_player()->query_name()+" drinks "+what+" from the "+str+".\n");
  ob->do_drink();
  return 1;
}
