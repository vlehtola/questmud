cmd_estimate(string skill) {
  int cost;
  if(!skill) {
    write("See 'help estimate'\n");
    return 1;
  }
  if ( !this_player()->query_skills(skill) ) {
    write("You don't know that skill.\n");
    return 1;
  }
  cost = call_other("/guilds/obj/skill", "get_ep_cost", skill,this_player());
  write("The skill '"+skill+"' takes "+cost+" endurance points.\n");
  return 1;
}
