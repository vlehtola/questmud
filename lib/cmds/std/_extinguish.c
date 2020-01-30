cmd_extinguish(string str) {
  object ob;
  if (!this_player()->check_condis()) { return 1; }
  if(!str) { write("Extinguish what?\n"); return 1; }
  ob = present(str, this_player());
  if(!ob) {
  write("You don't have such thing as '"+str+"'.\n"); return 1; }
  if(!ob->query_light_source()) { write("You can't extinguish that.\n"); return 1; }
  if(!ob->query_fuel()) { write("But "+str+" is already burned down and can be extinguished anymore.\n"); return 1; }
  if(!ob->query_lighted()) { write(str+" is not lighted.\n"); return 1; }
  write("You extinguish the "+str+".\n");
  say(this_player()->query_name()+" extinguish the "+str+".\n");
  ob->set_extinguish();
  return 1;
}
