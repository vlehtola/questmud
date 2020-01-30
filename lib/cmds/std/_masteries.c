status cmd_masteries(string arg) {
  mapping mastery;
  int i;
  string *index;
  object ob;
  if(arg && this_player()->query_wiz())
    ob = find_player(arg);
  if(!ob)
    ob = this_player();
  if(arg == "adjectives") {
        ("/cmds/std/_skills")->list_adjectives();
        return 1;
  }
  mastery = ob->query_mastery();
  if(mastery) index = m_indices(mastery);
  write("+-----------------------------------------------------+-------------+\n");
  write("| Personal knowledge gained by repetition and routine |       Value |\n");
  write("+-----------------------------------------------------+-------------+\n");
  for(i=0;i<sizeof(index);i++) {
     if(this_player()->query_wiz()) {
      printf("| %52-s| %11i |\n",index[i],mastery[index[i]]);
     } else {
      printf("| %52-s| %11-s |\n",index[i],"/guilds/obj/skillpros"->pros_names(mastery[index[i]]));
     }
  }
  write("+-----------------------------------------------------+-------------+\n");
  printf("| %52-s|\n","Total of "+sizeof(index)+" masteries");
  write("+-----------------------------------------------------+\n");
  write("See also help masteries, help mastery <mastery name>, masteries adjectives\n");
  return 1;
}
