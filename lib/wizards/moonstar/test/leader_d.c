/* Race leadership system by Cendor */
/* You can now take leadership if the leader has
   been away for 20 days. Rag 22.9.2003 */

//Chanced leadership to come from total worth instead of level. Moonstar
//Changed to 90d. Rag & Nalle 5.11.2003

#define SAVE_FILE "/data/leader"
#define CHANNEL_D "/daemons/channel_d"
#define DAYS 90 //Leader away for this many days to take leaderships

mapping leaders;

void reset() {
    leaders = ([ ]);
    if(file_size(SAVE_FILE + ".o") > 0) {
    restore_object(SAVE_FILE); 
    }
}

mapping query_leader() { return leaders[this_player()->query_race(),0]; }
mapping query_leaderi(string racee) { return leaders[racee,0]; }

int new_leader() {

  object ob;
  int since, level;
  string str, totals, race_name;

if(this_player()->query_wiz() || this_player()->query_tester() || this_player()->query_guest()) {
  write("You can not lead a race.\n");
  return 1;
}

    str = to_string(query_leaderi(this_player()->query_race()));
    str = lower_case(str);

		if ( str == lower_case( this_player()->query_name() ) ) {
			write("You already lead the "+this_player()->query_race()+" race.\n");
			return 1;
		}

    ob = find_player(str);
    if(ob) { ob->save_me(1);
    } else {
        ob = clone_object("obj/player.c");
        ob->restore_player(str);
    }

        level = ob->query_level();
        since = (time()-ob->query_enter_time())/86400;
        totals = ob->query_total_string();
        race_name = ob->query_race();

if(this_player()->query_race() == ob->query_race()) {

 if(since < DAYS) {
   if(call_other("daemons/explist.c","higher", totals, this_player()->query_total_string())) {
     write("You are not enough powerful to get the leadership.\n");
     return 1;
   }
 }
}

    leaders -= ([ this_player()->query_race() ]);
    leaders += (([ this_player()->query_race():this_player()->query_real_name() ]));
    save_object(SAVE_FILE);
    write("You are now the leader of " + this_player()->query_race() + " race.\n");
    CHANNEL_D->send_to_channel("inform", capitalize(this_player()->query_real_name()) + " is now the new leader of " + capitalize(this_player()->query_race()) + " race.");
    move_object(clone_object("guilds/obj/leader_eq.c"), this_object());
    return 1;
}

int remove_leader(string pam) {
  if(!pam) return 0;
  pam = lower_case(pam);
  leaders -= ([ pam ]);
  save_object(SAVE_FILE);
  return 1;
}

int test_leader(string name, string race) {
    if(!name) return -1;
    if(!race) return -1;
    name = lower_case(name);
    race = lower_case(race);
    if(name == this_object()->query_leaderi(race)) {
    return 1;
    } else {
    return 0;
    }
}





