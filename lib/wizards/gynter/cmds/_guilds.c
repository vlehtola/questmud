#define ALPHA "/daemons/alpha"

cmd_guilds(string str) {
  mapping guilds;
  string *lvl, spaces, name, level;
  int i;
  object ob;
  if(this_player()->query_guest()) { return call_other("/cmds/std/_help", "cmd_help", "guilds"); }
  if(str && this_player()->query_wiz()) ob = find_player(str);
  if(!ob) ob = this_player();

  guilds = ob->query_guild_level();
  lvl = m_indices(guilds);
  lvl = ALPHA->alpha(guilds);
spaces =
"                                   ";

  write("You are currently in the following guilds:\n");
  for(i=0; i < sizeof(lvl); i++) {
    name = capitalize(lvl[i]);
    level = "(lvl "+guilds[lvl[i]]+")";
    write(name + spaces[0..(strlen(spaces)-strlen(name)-strlen(level))] + level + "\n");
  }
  return 1;
}
