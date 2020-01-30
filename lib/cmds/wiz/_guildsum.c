status not_wiz(object ob) {
  return !ob->query_wiz();
}

void print(string guild, int lvl, int n, int total, int totaln ) {
  write( guild+"\n" );
  write("  Levels: "+lvl+" ("+lvl*100/total+"%) Players: "+n+" ("+n*100/totaln+"%)\n" );
}

int cmd_guildsum() {
  object *us;
  mapping guilds;
  int i, total, n;
  string tmp, tmp2, tmp3, *guild;

  guilds = ([]);

  us = filter(users(),"not_wiz");

  n = sizeof(us);

  for ( i = 0; i < n; i++ ) {

    guild = us[i]->query_starter_guild();

    if ( guild ) {
      tmp = guild[0];
    } else {
      tmp = "Reincer";
    }

    if ( !guilds[ tmp ] ) {
      guilds += ([ tmp: us[i]->query_level(); 1 ]);
    } else {
      guilds[ tmp, 0 ] = guilds[ tmp, 0 ] + us[i]->query_level();
      guilds[ tmp, 1 ]++;
    }
    total += us[i]->query_level();
  }

  walk_mapping(guilds,"print",this_object(),total, n);

  return 1;
}
