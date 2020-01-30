#define GUILDS "/wizards/gynter/cmds/fixed/guilddiv_d"

cmd_guilds2(string str) {
  mapping guilds;
  string *lvl, *pguilds;

  int i;
  object ob;
  if(this_player()->query_guest()) { return call_other("/cmds/std/_help", "cmd_help", "guilds"); }
  if(str && this_player()->query_wiz()) ob = find_player(str);
  if(!ob) ob = this_player();

  guilds = ob->query_guild_level();

  pguilds = GUILDS->check_subs(guilds);
  lvl = m_indices(guilds);

  //spaces = "                                             ";

  write("You are currently in the following guilds:\n");
  for(i=0;i<sizeof(lvl);i++) {
      /*level = "(lvl "+ pguilds[lvl[i], 0] +")";
      bonus = "Bonus: Str["+pguilds[lvl[i], 1]+"], Dex["+pguilds[lvl[i], 2]+
              "], Con["+pguilds[lvl[i], 3]+"], Int["+pguilds[lvl[i], 4]+
              "], Wis["+pguilds[lvl[i], 5]+"]";
      write(lvl[i] + spaces[0..(strlen(spaces)-strlen(lvl[i])-strlen(level))] + level + "\n" +
                     spaces[0..(strlen(spaces)-strlen(level))] + bonus +"\n");*/
      write(pguilds[i]+"\n");
  }
  return 1;
}