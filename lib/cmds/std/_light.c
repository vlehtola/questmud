cmd_light(string str) {
  object ob;
  if (!this_player()->check_condis()) { return 1; }
  if(!str) { write("light what?\n"); return 1; }
  ob = present(str, this_player());
  if(!ob) {
  write("You don't have such thing as '"+str+"'.\n"); return 1; }
  if(!ob->query_light_source()) { write("You can't light that.\n"); return 1; }
  if(!ob->query_fuel()) { write("But "+str+" is already burned down and can be lighted anymore.\n"); return 1; }
  if(ob->query_lighted()) { write(str+" is already lighted.\n"); return 1; }
  write("You light the "+str+".\n");
  say(this_player()->query_name()+" lights a "+str+".\n");
  ob->set_lighted();
  return 1;
}
