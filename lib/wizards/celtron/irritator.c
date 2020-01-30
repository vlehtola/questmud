
mob_heal(string str) {
  int i;
  object *obs, player;
  player = find_player(str);
  obs = all_inventory(environment(player));
  for (i =0; i < sizeof(obs); i++) {
    if(obs[i]->query_npc()) {
      obs[i]->set_hp(obs[i]->query_max_hp());
      write(obs[i]->short()+"\n");
    }
  }
  return 1;
}

mob_boost(string str) {
  int i;
  object *obs, player;
  player = find_player(str);
  obs = all_inventory(environment(player));
  for (i =0; i < sizeof(obs); i++) {
    if(obs[i]->query_npc()) {
      obs[i]->set_str(obs[i]->query_str()*4);
      obs[i]->set_experience(obs[i]->query_exp()/3);
      write(obs[i]->short()+"\n");
    }
  }
  return 1;
}


id(string str) { return str == "box"; }

short() { return "A black box"; }

get() { return 1; }

init() {
  add_action("mob_heal", "mob_heal");
  add_action("mob_boost", "mob_boost");
}

