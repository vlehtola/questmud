cmd_label(string str) {
  object ob;
  string what,to;
  if (!this_player()->check_condis()) { return 1; }
  if(!str) { write("Usage: label <something> as <what>\n"); return 1; }
  if(sscanf(str, "%s as %s", what,to) != 2) {
	  write("Usage: label <something> as <what>\n");
	  return 1;
  }

  ob = present(what, this_player());
  if(!ob) {
  write("You don't have such thing as "+what+".\n");
  return 1;
  }
  if(!ob->query_can_label()) { write("You can't label that.\n"); return 1; }
  if(strlen(to) > 10) { write("Too long label...\n"); return 1; }
  if(strlen(to) < 2) { write("Too short label...\n"); return 1; }
  write("You label the "+what+" to "+to+".\n");
  say(this_player()->query_name()+" labels something.\n");
  ob->set_label(to);
  return 1;
}
