cmd_fixme(string name) {
  string *starter, tmp;
  mapping guilds;
  object player;
  if(name && this_player()->query_wiz())
    player = find_player(name);
  else
    player = this_player();
  guilds = "/guilds/guilds/guild_init"->query_guilds();
  tmp = player->query_starter_guild();
  if(!stringp(tmp)) {
     write("already fixed..nothing done\n");
     return 1;
  }
  player->set_starter_guild( ({ guilds[tmp, 0], guilds[tmp,1], }) );
  write("done.\n");
  return 1;
}
