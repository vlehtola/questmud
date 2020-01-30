/* automatic race xp rate tune D, by Celtron */
/* drop 1% xprate of 2 most used races every boot and
raise 1% xprate for 2 less used ones */

#define RACE_D "/daemons/race_stats"
#define SAVEFILE "/data/xp_rate_d"

int time_to_act;	/* do not act, if booted and uptime < 23h */
mapping race_xp;	/* stores the xp done by mortals */
mapping tuned_race_xp_rate;

static void change_xp_rate(string race, int pros);
void process_tune(status override);

query_race_xp_rate(string race) {
  if(!race) return tuned_race_xp_rate;
  return tuned_race_xp_rate[race];
}

void reset(status arg) {
  if(arg) return;
  if(!restore_object(SAVEFILE)) {
    race_xp = ([ ]);
    tuned_race_xp_rate = ([ ]);
    time_to_act = 0;
    save_object(SAVEFILE);
  }
  process_tune(0);
}

/* Do not call this func //Celtron */
void reset_time_to_act() {
  if(this_player()->query_wiz() < 4) return;
  time_to_act = 0;
}

void add_race_xp(string race, int e) {
  if(!race || e<1) return;
  race = lower_case(race);
// 2 line mod added by C, 150904
  e = e / 100;
  if( e < 1 ) e = 1;
  if(!RACE_D->query_race_stat(race,"str"))
	return;
  if(race_xp[race])
    race_xp[race] += e;
  else
    race_xp += ([ race : e ]);

  save_object(SAVEFILE);
}


void process_tune(status override) {
  string *races, most_xp, alt_most_xp, less_xp, alt_less_xp;
  int *xps, i, high_xp, high_num;
  if(!override && time_to_act > time()) return;

  races = RACE_D->query_races();
  for(i=0; i < sizeof(races); i++) {
    add_race_xp(races[i], 1);
  }

  races = m_indices(race_xp);
  xps = m_values(race_xp);
  if(!sizeof(races)) return;

  /* find the most xp made race */
  for( i=0 ; i<sizeof(races) ; i++) {
    if(race_xp[races[i]] > high_xp) {
      high_xp = race_xp[races[i]];
      most_xp = races[i];
      high_num = i;
    }
  }

  /* reset highest xp, then find again the highest */
  race_xp[races[high_num]] = -1;
  high_xp = 0;

  for( i=0 ; i<sizeof(races) ; i++) {
    if(race_xp[races[i]] > high_xp) {
      high_xp = race_xp[races[i]];
      alt_most_xp = races[i];   
      high_num = i;
    }
  }
  race_xp[races[high_num]] = -1;

  /* less xp */
  high_xp = xps[0];

  for( i=0 ; i<sizeof(races) ; i++) {
    if(race_xp[races[i]] >= 0 && race_xp[races[i]] <= high_xp) {
      high_xp = race_xp[races[i]];
      less_xp = races[i];
      high_num = i;
    }
  }
  race_xp[races[high_num]] = -1;

  /* 2nd less xp */
  high_xp = xps[0];

  for( i=0 ; i<sizeof(races) ; i++) {
    if(race_xp[races[i]] >= 0 && race_xp[races[i]] <= high_xp) {
      high_xp = race_xp[races[i]];
      alt_less_xp = races[i];
      high_num = i;
    }
  }
  race_xp[races[high_num]] = -1; /* void */

  log_file("XP_RATE_D", ctime(time())+" Most: "+most_xp+" 2nd most "+alt_most_xp+" | Least: "+less_xp+" 2nd less "+alt_less_xp+"\n");

  /* if any value is missing, abort. balance must be kept. */
  if(most_xp && alt_most_xp && less_xp && alt_less_xp) {
    /* change rate */
    change_xp_rate(most_xp, -1);
    change_xp_rate(alt_most_xp, -1);
    change_xp_rate(less_xp, 1);
    change_xp_rate(alt_less_xp, 1);
  }

  time_to_act = time() + 23*60*60; /* after 23h */
  race_xp = ([ ]);

}

static void change_xp_rate(string race, int pros) {
  int org_xp;
  org_xp = RACE_D->query_race_stat(race, "exp_rate");
  if(!org_xp) log_file("XP_RATE_D", ctime(time())+" Failed. race: "+race+"\n");

  if(tuned_race_xp_rate[race]) {
/*    if(org_xp - 10 <= tuned_race_xp_rate[race] || org_xp + 10 >= tuned_race_xp_rate[race])
	return;
*/
    tuned_race_xp_rate[race] += pros;
  } else {
    tuned_race_xp_rate += ([ race : (org_xp + pros) ]);
  }
}
