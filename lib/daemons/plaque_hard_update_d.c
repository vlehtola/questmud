/* daemon that hard updates the plaque from all /player-directory savefiles //Celtron */

#define PLAQUE 		"/daemons/explist"
#define PLAYER_DIR 	"/players/"
#define PROCESS_AMOUNT	1	/* amount of playerupdates done each tic */

static int process, counter;
void plaque_hard_update(mixed arg, status continue_);

/* purges long gone low worth ppl */
void player_purger(string arg) {
  object player;
  string tmp;
  if(this_player()->query_name() != "Celtron") return;
  player = clone_object("/obj/player");
  player->restore_player(arg);   
  tmp = ctime(player->query_enter_time());
  if(strlen(player->query_total_string()) < 7 && tmp[strlen(tmp)-5..strlen(tmp)-1] != " 2001") {
    write("rm\n");
    rm(PLAYER_DIR+arg+".o");
    counter += 1;
  }
  destruct(player);
}

static void hard_update_players(string a, int from) {
  string *names;
  int i;
  names = get_dir(PLAYER_DIR+a+"*.o");
  for(i=from; (i < sizeof(names) && i < from + PROCESS_AMOUNT); i++) {
    names[i] = names[i][0..strlen(names[i])-3];
    write(names[i]+", ");
    player_purger(names[i]);
  /*  PLAQUE->update_plaque(names[i], 1); 1 means silenced */
  }
  if(i >= sizeof(names))
    call_out("plaque_hard_update", 1, 0,1);
  else 
    call_out("hard_update_players", 1, a, i);
}

/* do not run this func, you have no idea what it costs!! */
void plaque_hard_update(mixed arg, status continue_) {
  string *abc;
  abc = ({ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "w", "v", "x", "y", "z", });
  if(this_player()->query_name() != "Celtron") return;
  if(!continue_ && process) {
    write("Processing already..\n");
    return;
  } else if (!continue_) {
    write("Processing started..\n");
    process = 0;
  }
  if(process >= sizeof(abc)) {
    write("Plaque hard update completed. Counter: "+counter+"\n");
    process = 0;
    return;
  }
  write(abc[process]+")\n");
  hard_update_players(abc[process],0);
  process += 1;
}
