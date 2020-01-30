#define XP_RATE_D "/daemons/xp_rate_d"
#define STATS "/daemons/race_stats"

cmd_exprates(string arg) {
  string races, tmp, empty;
  int rate;
  int i,x;
  empty = "                 ";
  races = m_indices(XP_RATE_D->query_race_xp_rate());
  rate = m_values(XP_RATE_D->query_race_xp_rate());
  write("Racial exprates(%) ("+ctime(time())+"):\n");
  for(i=140;i > 50; i--) {
    for(x=0; x < sizeof(rate); x++) {
      if(rate[x] == i) {
        //Non-rebirthers can't see the exprates of the rebirth races -- Rag 15.9.2004
        if ( STATS->query_race_stat(races[x],"rebirth")
             <= this_player()->query_rebirth() || this_player()->query_wiz() ) {
          tmp = races[x]+": ";
          write(tmp+empty[0..14-strlen(tmp)]+i+"\n");
        }
      }
    }
  }
  return 1;
}

