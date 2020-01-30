/* Area Heal (uses basic heal) //Celtron */

#define HEAL "/guilds/spells/channel/_chl_hea_min"

status is_target(object ob) {
  if(living(ob)) return 1;
  return 0;
}

/* bonus [0,300] */
resolve(int bonus, string target, object spell) {
  object *ob;
  int i;
  string healed;
  if(!spell) spell = this_object();
  ob = all_inventory(environment(this_player()));
  ob = filter_array(ob, "is_target", spell);

  healed = "";
  for(i=0; i < sizeof(ob); i++) {
    ob[i]->heal_hp(HEAL->get_heal_amount(bonus));
    healed += ob[i]->query_name();
    if(i+2 < sizeof(ob))
	healed += ", ";
    else if(i+1 < sizeof(ob))
	healed += " and ";
  }
  if(healed == "") {
    write("There is no one to be healed.\n");
    return 1;
  }
  write("You heal "+healed+".\n");
  say(this_player()->query_name()+" heals "+healed+".\n");
}
