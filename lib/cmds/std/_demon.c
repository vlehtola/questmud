#define WARLOCK_D "/daemons/warlock_d"
order_demon(string what, string misc, int xp) {
  object demon;
  object *obs;
  int i;
  int hp, ep, sp;
  demon = WARLOCK_D->query_demon(this_player()->query_real_name());
  if(!demon) {
  write("You don't have a demon.\n");
  return 1;
  }
  if(what == "dismiss") {
  obs = all_inventory(demon);
  for(i=0;i<sizeof(obs);i++) {
  if(!obs[i]->drop()) {
  move_object(obs[i], environment(demon));
  }
  }
  destruct(demon);
  write("You dismiss your demon.\n");
  return 1;
  }
  if(what == "report") {
  hp = (demon->query_hp() * 100) / demon->query_max_hp();
  ep = (demon->query_ep() * 100) / demon->query_max_ep();
  sp = (demon->query_sp() * 100) / demon->query_max_sp();
  write("Hp: ["+hp+"]% Ep: ["+ep+"]% Sp: ["+sp+"]%\n");
  return 1;
  }
  switch(what) {
  case "follow": return WARLOCK_D->do_follow(demon);
  case "attack": return WARLOCK_D->do_kill(misc, demon);
  case "get": return WARLOCK_D->do_get(misc, demon);
  case "drop": return WARLOCK_D->do_drop(misc, demon);
  case "say": return WARLOCK_D->do_say(misc, demon);
  case "use": return WARLOCK_D->do_skill(misc, demon);
  case "cast": return WARLOCK_D->do_spell(misc, demon);
  case "eat": return WARLOCK_D->do_eat(misc, demon);
  case "set": return demon->set_demon(misc, xp);
  case "skill": return demon->set_skill_name(misc);
  case "alias": return demon->set_alias(misc);
  case "spell": return demon->set_spell_name(misc);
}
demon->init_command(what);
}
cmd_demon(string str) {
  object *obs;
  object demon;
  string tmp;
  int i;
  if (!this_player()->check_condis()) { return 1; }
  if(!this_player()->query_guild_level("Warlocks")) return;
  if(!str) {
  write("Usage: demon <command>\nCommands are:\n"+
  "follow, attack <target>, get <something>, drop <something>, use <skill | at target>, cast <spell>, say <something>, dismiss, alias (something), report, eat <something>\n"+
  "set <share [number] | use <skill|stop> | spell <spell|stop> | tank\n"+
  "Examples:\n"+
  "demon set spell chl hea min at demon\n"+
  "demon set use kick at citizen\n"+
  "demon set spell chl xfr min at salesman\n"); return 1; }
  if(sscanf(str, "attack %s", tmp) == 1) {
  order_demon("attack", tmp);
  return 1;
  }
  if(sscanf(str, "kill %s", tmp) == 1) {
  order_demon("attack", tmp);
  return 1;
  }
  if(sscanf(str, "get %s", tmp) == 1) {
  order_demon("get", tmp);
  return 1;
  }
  if(sscanf(str, "drop %s", tmp) == 1) {
  order_demon("drop", tmp);
  return 1;
  }
  if(sscanf(str, "say %s", tmp) == 1) {
  order_demon("say", tmp);
  return 1;
}
if(sscanf(str, "set share %d", i) == 1) {
  order_demon("set", "exp", i);
  return 1;
}
if(sscanf(str, "eat %s", tmp) == 1) {
  order_demon("eat", tmp);
  return 1;
}
if(sscanf(str, "set use %s", tmp) == 1) {
  order_demon("skill", tmp);
  return 1;
}
if(sscanf(str, "set spell %s", tmp) == 1) {
 order_demon("spell", tmp);
 return 1;
}
if(sscanf(str, "set %s", tmp) == 1) {
  order_demon("set", tmp);
  return 1;
}

if(sscanf(str, "use %s", tmp) == 1) {
  order_demon("use", tmp);
  return 1;
}
if(sscanf(str, "cast %s", tmp) == 1) {
  order_demon("cast", tmp);
  return 1;
}
if(sscanf(str, "alias %s", tmp) == 1) {
  order_demon("alias", tmp);
  return 1;
}
order_demon(str);
return 1;
}
