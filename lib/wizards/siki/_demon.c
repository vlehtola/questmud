#define WARLOCK_D "/daemons/warlock_d"
order_demon(string what, string misc, int xp) {
  object demon;
  object *obs;
  int i;
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
  switch(what) {
  case "follow": return WARLOCK_D->do_follow(demon);
  case "attack": return WARLOCK_D->do_kill(misc, demon);
  case "get": return WARLOCK_D->do_get(misc, demon);
  case "drop": return WARLOCK_D->do_drop(misc, demon);
  case "say": return WARLOCK_D->do_say(misc, demon);
  case "use": return WARLOCK_D->do_skill(misc, demon);
  case "cast": return WARLOCK_D->do_spell(misc, demon);
  case "set": return demon->set_demon(misc, xp);
  case "call": return demon->set_demon(misc, this_player()->query_skills("knowledge of chaos"));
  case "skill": return demon->set_skill_name(misc);
  case "summon": return demon->do_summon();
  case "teleport": return demon->do_teleport();
  case "alias": return demon->set_alias(misc);
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
  if(!str) { write("Usage: demon <command>\nCommands are:\n"+
  "follow, attack <target>, get <something>, drop <something>, use <skill | at target> set <share [number] | use <skill>>, say <something>, dismiss, alias (something)\n"); return 1; }
  if(str == "follow") {
  order_demon("follow");
  return 1;
  }
  if(str == "dismiss") {
  order_demon("dismiss");
  return 1;
  }
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
if(sscanf(str, "set use %s", tmp) == 1) {
  order_demon("skill", tmp);
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
