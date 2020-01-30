status cmd_alias(string str) {
  mapping aliases;
  string *map;
  int i;
  aliases = this_player()->query_aliases();
if(aliases) {
  map = m_indices(aliases);
  write("You currently have these aliases:\n");
  for(i=0;i<sizeof(map);i++)
     write(map[i]+" -> "+aliases[map[i]]+"\n");
  write("Total of "+sizeof(map)+" alias(es).\n");
} else {
  write("You have no aliases defined!\n");
}
return 1;
}
