cmd_where() {
  object *all;
  string tmp;
  string *names;
  mapping who;
  int i;
  int x;

  who = ([ ]);
  all = users();

  write("\nPlayers\t\tLocation\n\n");
  for (i=0;i<sizeof(all);i++) {
    who += ([ capitalize(all[i]->query_name()): file_name(environment(all[i])) ]);
  }
  
  names = m_indices(who);
  
  for ( i = 0; i<sizeof(names) ; i++) {
  	
  	write(" "+names[i]+"      "+who[names[i]]+" \n");
}
return;
}
