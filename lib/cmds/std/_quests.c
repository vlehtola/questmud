//Wizards can see players' quests -- Rag 1.10.2005

cmd_quests(str) {
  string *quests;
  object plr;
  int i,x;
  plr = this_player();
  if ( str && this_player()->query_wiz() ) {
    plr = find_player(str);
    if ( !plr ) {
      write(capitalize(str)+" was not found!\n");
      return 1;
    }
  }
  if(!plr->query_quests()) {
    write("You have not solved any quests.\n");
    return 1;
  }
  quests = explode(plr->query_quests(),"#");
  write("You have done these quests so far:\n");
  for(i=0;i<sizeof(quests);i++)
     for(x=0;x<(strlen(quests[i])-1);x++)
        if(quests[i][x] == '_') quests[i][x] = ' ';
  for(i=0;i<sizeof(quests);i++)
  write((i+1)+". "+quests[i]+"\n");
  return 1;
}
