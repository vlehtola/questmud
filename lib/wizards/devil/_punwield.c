cmd_punwield(string str) {
  object ob;
  if(!str) { write("punwield what?\n"); return 1; }
  ob = present(str, this_player());
  if(!ob) { write("You don't have any "+str+".\n"); return 1; }
  if(!ob->query_weapon()) { write("You are not wielding that.\n"); return 1; }
  if(ob->query_wielded()) {
  write("You punwield your "+ob->query_name()+".\n");
  ob->set_wielder(0);
  this_player()->stop_wielding(this_object());
  ob->disable_forced2h();
  return 1;
}
  write("You are not wielding "+str+".\n");
  return 1;
}