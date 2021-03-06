#include "log.h"
#include "living.h"

#define BANISH_D "/room/banish_d"
#define XP_TUNE_D "/daemons/xp_rate_d"
#define RACE_D "/daemons/race_stats"
#define STAT_D "/obj/player_stats"
#define SHOUT_OLD(x) shout(x)
#define SHOUT(x) gTellstring=x; filter_tell()
#define WIZLOCK 0
#define BANISH_D "/room/banish_d"
#define CHANNEL_D "/daemons/channel_d"
#define LEADER_D "/daemons/leader_d"
#define GUILDRANK_D "/daemons/guildrank_d"
#define CONVERSE 11
#define SAVEMODE 1
#define REGEN_TIME	30      /* secs */
#define MAX_SCAR        11
#define AMOUNT_OF_COMMANDS 120  /* oikee amount = amount / 2 */
#define QUEST_D "/daemons/quest_d"
#define SKILLFUN "/guilds/obj/skillfun"
#define NEWS_D "/daemons/news_d"
#define CLAN_D "/clan/clan_d"
#define COMMAND_D "/obj/command_d"
#define SIMUL	"/secure/simul_efun"
#define DEATH_LEGACY_TIME       300    /* 5mins */
#define MAX_LEVEL	400
#define EMOTE_D "/daemons/emote_d"
#define IGNORE "/cmds/std/_ignore"
#define GUILD "/guilds/guilds/guild"
#define SKILL_LEARN_D "/daemons/skill_learn_d"
#define INVISIBILITY_D "/daemons/invisibility_d"

#define REBIRTH_OB "/obj/rebirth"
#define REBIRTH_SKILLS_BONUS	10
#define REBIRTH_RESISTS_BONUS	15

mapping news_data;
mapping mastery;
mapping aliases;

mapping explored; // Testing by Nalle - Apr 2003
int explore_version=1;

static int death_legacy_time;
static string last_command;
static mapping keep;
static object myself;           /* Ourselfs. */
static string title;
string password;                /* This players crypted password. */
string surname;
string plan;
string wiz_short, set_short;
static string password2;        /* Temporary when setting new password */
string al_title;
string clan;			/* part of a clan ? (apumuuttuja) */
int clan_deaths;
string *ignored;
mapping notes;                  /* Notebook data */
int scar;
int invisible;
int intoxicated;                /* How many ticks to stay intoxicated. */
int stuffed;                    /* How many ticks to stay stuffed */
int soaked;                     /* How many ticks to stay soaked */
int headache, max_headache;
string called_from_ip;          /* IP number was used last time */
string quests, reinc_quests;    /* A list of all quests, reinc_quests clear in reinc */
int last_reinc_time;
static int time_to_save;        /* Time to autosave. */
static int time_for_growth;
static int link_dead;
static int see_in_dark;
static int exp_summary, money_summary;
static string saved_where;      /* Temp... */
string mailaddr;                /* Email address of player */
static string it;               /* Last thing referenced. */
int bbrief;
static string current_path;     /* Current directory */
static wrong_pwd, under_pwd_query;

static string last_teller, last_msg;  /* last tell/reply strs*/
static string *last_tells, *say_messages;
static mapping resists;
static string t_status;

static object ld_location;
int stats_is_updated;
int enter_time, time_ld;
mapping kills;			/* var to reduce mass murdering of the same monster */
static int kill_reset_time;
int battle;			/* battle briefing */
static int chan_delay;
static int skill_trained;
static int set_parry, df, af, c_df; 
static string last_command, history;
string command;
static int belling;
mapping skills, boosted_skills;
mapping skill_trains;
int tester;
static int guest;
mapping guild_levels;
int exp_gag_limit;
int skill_train, skill_left, skill_costs, skill_exps, skill_teach;
int level_cost, level_exp;
string level_name, level_bonus, level_guild;
string totals, free_exp;
string race_name;
mapping stat_max, stat_percent, traits;
static mapping stat_trait;
int race_exp_rate, exp_rate,skill_max,spell_max;
int base_hp_regen, base_sp_regen, base_ep_regen;
int hp_regen, sp_regen, ep_regen;
int last_hp,last_sp,last_ep,sc_on;
int terminal, counter, elusive;
string counter_target;
mapping sp_boosts;			/* Spelltype sp boost array */
string safe_load, recovery_load;
string best_solo, best_party;			      /* Best kills */
int best_solo_exp, best_party_exp, best_party_number; /* Best kills */
int hunger, thirst, number_of_scars;
string prom, away;
string *lochannels;
int conversed;
int quest_points, max_quest_points, level_paid;
int created_in, real_age;
int lesser_wishes, greater_wishes, task_points, max_task_points;
int lesser_number, greater_number, max_level;
int al_change, god_status; /* like alignment */
mapping friends;
string starting_location;
string *criminal_record;
string *starter_guild;		// background or such (0 guildname, 1 guildfile)
static object party_object;
mapping colors;			// custom colors, if any
mapping environment_colors;	// custom colors, for aggromons etc
int rebirth_time, rebirth_points;	// when did rebirth occur
string married;
mapping skill_learn;

void set_married(string str) { married = str; }
string query_married() { return married; }

void set_status(string str) { t_status = str; }
string query_status() { return t_status; }

mixed query_rebirth(string special) {
  if(!rebirth_time) return 0;
  if(!special) return 1;
  return REBIRTH_OB->query_rebirth(special, this_object());
}

// gimme a rebirth
do_rebirth() { 
  if(file_name(environment(this_object() ))[0..16] != "/obj/rebirth_room") return 0;
  rebirth_time = time();
  if(sscanf(free_exp[0..1], "%d", rebirth_points)) { }
  reset_free_exp();
  reset_totals();
  save_me(1);
  return 1;
}

// 'Lite' data

mapping query_colors() { return colors; }

mapping set_colors(mapping x) {
  colors = x;
  return colors;
} 

// 'Environment' data

mapping query_environment_colors() { return environment_colors; }

mapping set_environment_colors(mapping x) {
  environment_colors = x;
  return environment_colors;
} 

// 'Note' data
      
mapping query_notes() { return notes; }

mapping set_notes(mapping x) {
  notes = x;
  return notes;
}       

//

void set_starter_guild(string *guild) {
  starter_guild = guild;
}

string *query_starter_guild() {
  return starter_guild;
}

status add_record(string str) {
  if(!str || this_player()->query_wiz() < 3)
	return 0;
  str = ctime(time())+" "+this_player()->query_name()+": "+str;
  if(!criminal_record)
    criminal_record = ({ str, });
  else
    criminal_record += ({ str, });
  return 1;
}

string *query_record() {
  return criminal_record;
}

mapping set_mastery(string str,int i) {
  if(!mastery) mastery = ([ str:i, ]);
  else if(!mastery[str]) mastery += ([ str:i, ]);
  else mastery[str] = i;
  if(!i) mastery = m_delete(mastery,str);
  write("You feel like your profession over something has gone better!\n");
  return mastery;
}

mapping query_mastery() {
if(!mastery) mastery = ([ ]);
return mastery;
}

// Explore-code testing by Nalle

mapping query_explored() 
{
if(!explored) explored = ([ ]);
return explored;
}

void set_explored(string explore_hash) 
{
if(!explored) explored = ([ ]);
explored+=([explore_hash : 0]);
}

//

mapping query_friends() { return friends; }

mapping set_friends(mapping x) {
  if(!mappingp(x)) x= ([ ]);
  return friends=x;
}


/* Some functions to set moving messages. */

setmout(m) { msgout = m; return 1; }
setmin(m) { msgin = m; return 1; }
setmmout(m) { mmsgout = m; return 1; }
setmmin(m) { mmsgin = m; return 1; }

review() {
    write("mout:\t" + msgout +
	  "\nmin:\t" + msgin +
	  "\nmmout:\t" + mmsgout +
	  "\nmmin:\t" + mmsgin + "\n");
    return 1;
}

query_last_reinc_time() {
  return last_reinc_time;
}

query_msgin() { return msgin; }
query_msgout() { return msgout; }
query_mmsgin() { return mmsgin; }
query_mmsgout() { return mmsgout; }

/* logon() is called when the players logges on. */

static logon() {
    int ran;
    object timer;
    time_to_save = 300;
    name = "logon";
    write("Welcome to QuestMud (Questlib v1.3)\n");
    if (WIZLOCK == 0) {
       ran = random(3) + 1;
       if (ran == 1) {
          cat("/WELCOME");
       }
       if (ran == 2) {
          cat("/WELCOME2");
       }
       if (ran == 3) {
          cat("/WELCOME3");
       }
    }
    else {
   	cat("/WIZLOCKED");
    }
    write("\n");
 
    write("[c] Create new character          [g] Enter as a guest\n");
    write("[w] Who are currenly playing      [q] Quit\n");
    write("\n");
    timer = find_object("/obj/timer");
    if (timer && timer->query_time_to_boot(1) < 1800) {
      write("Reboot in "+timer->query_time_to_boot()+"\n");
    }
    write("Command or Name: ");
    input_to("logon2");
    call_out("time_out", 120);
    return 1;
}

/* Define this after it was used. */
version() {
    return "1.00";
}

object other_copy;

pause(str) {
  if(wrong_pwd) destruct(this_object());
  logon();
}

query_pwd_query() {
  return under_pwd_query;
}

static logon2(str) {
    string tmp,tmp2;
    if (!str || str == "") {
	input_to("logon2");
	write("Command or name: ");
	return;
    }
    if (name != "logon") {
	illegal_patch("logon2 " + name);
	destruct(this_object());
	return;
    }
    str = lower_case(str);
    if (str == "q") {
	write("See you later.\n");
	destruct(this_object());
	return;
    }
    if (str == "w" || str == "W") {
       call_other("/cmds/std/_who", "cmd_who", "short");
	write("\n[Enter] to continue.\n");
	input_to("pause");
	return;
    }

    if (str == "g" || str == "G") {
      if(BANISH_D -> check_banned_site(query_ip_number(this_player()))) {
        write("Your site has been replaced from our services. Only existing characters may enter. ("+
        BANISH_D -> query_sreason(query_ip_number(this_player())) +")\n");
        destruct(this_object());
        return 0;
      }
      if (WIZLOCK > 0) {
	    write("The game is wizlocked and no guests may enter.\n");
	    logon();
	    return;
      }
	write("Logging in as a guest.\n");
	logon_guest();
	return 1;
    }
    if (str == "c" || str == "C") {
      if(BANISH_D -> check_banned_site(query_ip_number(this_player()))) {
        write("Your site has been replaced from our services. Only existing characters may enter. ("+
        BANISH_D -> query_sreason(query_ip_number(this_player())) +")\n");
        destruct(this_object());
        return 0;
      }
	if (WIZLOCK > 0) {
	    write("The game is wizlocked and no mortals may enter.\n");
	    logon();
	    return;
	}

        input_to("creation");
	write(
"\nFirst you are required to give a name for your character.\n"
"Because this is fantasy RPG mud, it should be of medieval nature.\n\n");

	write("Give a name to your character ('q' to quit): ");
	return;
    }
    if (sscanf(str, "%s..%s",tmp,tmp2) ||
          sscanf(str, "%s %s",tmp,tmp2) || str &&
	  !restore_object("players/"+str) &&
	  !restore_object("converse/"+str)) {
	write("No such player.\n");
	logon();
	return;
    }
    if (!Wiza && !tester && WIZLOCK) {
	write("The game is wizlocked and no mortals may enter.\n");
	name = "logon";
	password = 0;
	logon();
	return;
    }
    if (!tester && Wiza < WIZLOCK) {
    	write("The game is high wizard locked and you are not allowed to" +
              " enter just now.\n");
        name = "logon";
	password = 0;
	logon();
	return;
    }

    time_to_save = age + 300;
    /*
     * Don't do this before the restore !
     */
    name = str;                 /* Must be here for a new player. */
    dead = ghost;
    myself = this_player();
    cap_name = capitalize(name);

    local_weight = 0;
    armour_class = 0;
    name_of_weapon = 0;
    name_of_right_weapon = 0;
    name_of_left_weapon = 0;
    if (!skill_teach) { skill_teach = allocate(10); }
    if (!command) { command = allocate(AMOUNT_OF_COMMANDS); }
    history = allocate(20);

    under_pwd_query = 1;
    input_to("check_password", 1);
    write("Password: ");
    if (name == "guest")
	write("(just CR) ");
    attacker_ob = 0;
    alt_attacker_ob = 0;
    return;
}

static creation(str) {
    if (!str || str == "") {
	input_to("creation");
	write("Give a name to your character ('q' to quit): ");
	return;
    }
    if (name != "logon") {
	illegal_patch("logon2 " + name);
	destruct(this_object());
	return;
    }
    str = lower_case(str);
    if (str == "q") {
	write("As you wish.. Quitting.\n");
	destruct(this_object());
	return;
    }
    if (!valid_name(str)) {
	input_to("creation");
	write("Give name again: ");
	return;
    }
    if (file_size("/players/" + str + ".o") != -1) {
	write("That name is already in use.\n");
	input_to("creation");
	write("Give name again: ");
	return;
    }
    if (file_size("/converse/" + str + ".o") != -1 ||
	   file_size("/banish/"+str) != -1) {
	write("That name is reserved.\n");
	input_to("creation");
	write("Give name again: ");
	return;
    }
    if(strlen(str) > 10 || strlen(str) < 2) {
        write("Your name should contain from 2 to 10 letters.\n");
        input_to("creation");
        write("Give name again: ");
        return;
    }
    allocate_variables("continue_start", str);
}

allocate_variables(str, name_str) {
    level = 0;
    command = allocate(AMOUNT_OF_COMMANDS);
    skills = ([ ]);
    guild_levels = ([ ]);
    skill_trains = ([ ]);
    skill_train = allocate(10);
    skill_left = allocate(10);
    skill_costs = allocate(10);
    skill_exps = allocate(10);
    skill_teach = allocate(10);
    history = allocate(20);
    level_cost = 0;
    level_exp = 0;
    stat_max = ([ ]);
    stat_trait = ([ ]);
    traits = ([ ]);
    sp_boosts = ([ ]);
    sp_boosts["offensive"] = 40;
    if (str) { call_other(this_object(), str, name_str); }
}

continue_start(str) {
    time_to_save = age + 300;

    /*
     * Don't do this before the restore !
     */
    name = str;                 /* Must be here for a new player. */
    dead = ghost;
    myself = this_player();
    cap_name = capitalize(name);

    input_to("new_password", 1);
    write("Password: ");
    if (name == "guest")
	write("(just CR) ");
    attacker_ob = 0;
    alt_attacker_ob = 0;
    return;
}

reset_clan_deaths() {
  clan_deaths = 0;
}

logon_guest() {
  int i;
  string tmp;
  object ob;
  guest = 1;
  i = 1;
  while(i < 10) {
    tmp = "guest-"+i;
    ob = find_player(tmp);
    if (!ob || ob && ob->query_link_dead()) {
	if (ob) { destruct(ob); }
	name = tmp;
	break;
    }
    i += 1;
  }
  if (!name) {
    write("Too many guests in game. Try again later.\n");
    destruct(this_object());
    return 1;
  }
  conversed = CONVERSE;
  myself = this_object();
  cap_name = capitalize(name);
  allocate_variables();
  level = 1;
  race_name = "visitor";
  exp_rate = 100;
  move_player_to_start3();
  return 1;
}

query_guest() { return guest; }

/* Called by command 'save' */
save_character() {
    if (guest) { write("Guests can't save.\n"); return 1; }
    if (level < 2 && age < 3600) { 
	write("Characters below level 2 are not saved.\n");
   	return 1;
    }
    if(save_me(1))
      write("Saving..\n");
    else
      write("No save mode.. cannot save character.\n");
    return 1;
}

reset(arg) {
    if (arg)
	return;
/*
 *   With arg = 0 this function should only be entered once!
 */
    if(myself) return;
    if (creator(this_object())) {
	illegal_patch("Cloned player.c");
	destruct(this_object());
	return;
    }
    level = -1;
    name = "logon";
    cap_name = "Logon";
    msgin = "arrives"; msgout = "leaves";
    mmsgin = "arrives in a puff of smoke";
    mmsgout = "disappears in a puff of smoke";
    title = 0;
    al_title = "neutral";
    gender = -1; /* Illegal value, so it will be changed! */
    lochannels = ({});
    skills = ([ ]);
    kills = ([ ]);
    stat_max = ([ ]);
    stat_trait = ([ ]);
    traits = ([ ]);
    stat_percent = ([ ]);
    combat_tactic = ([ ]);
    keep = ([ ]);
    resists = ([ ]);
}

add_kills(string str) {
  if(kills[str]) kills[str] += 1;
  else kills += ([str:(int) 1]);
}
query_kills(string str) {
  if(!str) return kills;
  return kills[str];
}
/* Enable other objects to query our hit point. */
query_hit_point() {
    return hit_point;
}

check_condis() {
  if (uncon) {
    write("You are unconcious and unable to do anything.\n");
    return 0;
  }
  if (this_object()->query_stun()) {
    write("You are stunned and unable to do anything.\n");
    return 0;
  }
  if (sleep) {
    write("You are asleep and unable to do anything.\n");
    return 0;
  }
  if (ghost) {
    write("You are in immaterial state and unable to do anything.\n");
    return 0;
  }
  return 1;
}

status news_security_filter(string str) {
  if(str[0..3]=="wiz." && !this_object()->query_wiz())
    return 0;
  if(str[0..3]=="adm." && this_object()->query_wiz() < 4)
    return 0;
  if(str[0..4]=="arch." && this_object()->query_wiz()< 3)
    return 0;
  return 1;
}

mapping query_news_data() {
  mapping rv;
  string *ind;
  int i;
  if(!news_data)
    return ([ ]);
  rv = ([ ]);
  ind = m_indices(news_data);
  ind = filter_array(ind, "news_security_filter", this_object());
  for(i=0;i<sizeof(ind);i++) {
    rv += ([ ind[i] : news_data[ind[i]] ]);
  }
  news_data = rv;
  return news_data;
}

int query_read_id(string group) {
  if(!news_data)
    return 0;
  return (news_data[group]) ? news_data[group] : 0;
}

int news_hack(string group, int id) {
  if(!news_data)
    news_data = ([ ]);
  news_data[group] = id;
}

query_skill_max(cost) {
  return (skill_max + 25) - (cost * 5);
}

query_spell_max(cost) {
  return (spell_max + 25) - (cost * 5);
}

query_guild_level(string num) {
  string str;
  if(query_level() < 0 || query_guest()) return 0;
  if(!num) return guild_levels;
  if(!stringp(num)) log_file("QUERY_GUILD_LEVEL", ctime(time())+" "+query_name()+" "+num+"\n");
  str = lower_case(num);
  return guild_levels[str];
}

advance_guild_level(string num, level_bon) {
    int i, c;
    if (!num) {
	return 1;
    }
    num = lower_case(num);
    guild_levels[num] += 1;
    if (!Wiza) {
        set_level(level + 1);
    }
    if (!level_bonus) {
	level_bonus = level_bon;
    }
    if (level_bonus) {
	resolve_bonuses();
	level_bonus = 0;
    }
    set_level_paid();
    c = 1;
    if(query_level() > 100) c = 2;
    stat_percent["str"] += c;
    stat_percent["dex"] += c;
    stat_percent["con"] += c;
    stat_percent["int"] += c;
    stat_percent["wis"] += c;

    update_stats();
}

resolve_bonuses() {
    int bonus;
    string arg;
    while(sscanf(level_bonus, "%s %d , %s",arg, bonus, level_bonus) == 3) {
	stat_percent[arg] += bonus;
    } 
    if (sscanf(level_bonus, "%s %d , ",arg, bonus) == 2) {        
      stat_percent[arg] += bonus;
    }
    this_object()->update_stats();
}

modify_plan(str) {
  if (str == "clear") {
    write("Plan cleared.\n");
    plan = 0;
    return 1;
  }
  if (str == "set") {
    if (plan) {
      write("Are you sure? [y/n]\n");
      input_to("plan_choice");
    } else {
      set_plan();
    }
    return 1;
  }
  write("Usage: plan <set/clear>\n");
  return 1;
}

plan_choice(str) {
  if (str == "y") { set_plan(); }  
  return 1;
}

set_plan() {
  object ob;
  int lines;
  lines = 6;
  if(query_wiz()) lines = 9;
  ob = clone_object("/daemons/editor");  
  ob->start("make_plan", lines);
  return 1;
}

make_plan(string str) {
  if(strlen(str) > 500) {
    write("Aborting.. too long.\n");
    return 1;
  }
  write("Plan set.\n");
  plan = str;
  return 1;
}

rep(str) {
  object ob;
  if (!str) {
    write("Usage: rep <string>\n");
    return 1;
  }
  ob = clone_object("/daemons/rep.c");
  ob->start(str);
  return 1;
}

update_stats() {
    object ob;
    int i, stat, scar_modifier, hpr, t, temp_res;
    string c, *eq_res;

    if(guest) { return; }
    stat = allocate(9);
    stat_trait = ([ ]);
    resists = ([ ]);
    call_other("/world/special/traits", "update_traits", this_object());
    fix_ac();
    c = ({"str","dex","con","int","wis",});
    ob = first_inventory(myself);
    while(ob) {
      i = 0;
      if (ob->query_worn() || ob->query_wielded()) {
	while(i<sizeof(c)) {	  
	  stat[i+1] += call_other(ob, "query_stats",c[i]);
	  i += 1;
        }
        stat[7] += call_other(ob, "query_stats","spregen");
	stat[8] += call_other(ob, "query_stats","epregen");
        eq_res = ob->query_resists();
        if(eq_res) {
        	if(resists[eq_res[0]]) {
        		temp_res = resists[eq_res[0]];
        		resists -= ([ (string) eq_res[0] ]);
        	} else {
        		temp_res = 0;
        	}
        	resists += ([ (string) eq_res[0] : (int) eq_res[1]+temp_res ]);
        }
      }
      ob = next_inventory(ob);
    }

    hp_regen = STAT_D->get_hp_regen(base_hp_regen, query_level());
    sp_regen = STAT_D->get_sp_regen(base_sp_regen, query_level()) + stat[7]; /* eq gives spr */
    ep_regen = STAT_D->get_ep_regen(base_ep_regen, query_level());

    scar_modifier = 100 - number_of_scars*4;
  for(i=0; i < sizeof(c) ; i++) {
    // race percent + eq percent 
    t = stat_percent[c[i]] + stat[i+1] - clan_deaths;
    // scars, race_max + traitbonuses
    t = t * scar_modifier * ( stat_max[c[i]] + stat_trait[c[i]] );
    // divide for scar_m and stat percent
    t = t / 10000;
    // stat cap
    if(t > 350) t = 350 + (t-350)/2;
    call_other(this_object(), "set_"+c[i], t);
  }
  exp_rate = race_exp_rate + stat_percent["exp_rate"];

// rebirth chars don't get under 90% exprate

  if(query_rebirth() && race_exp_rate < 90)
    exp_rate = 90 + stat_percent["exp_rate"];

}

query_sp_regen() {
  return sp_regen;
}

query_hp_regen() {
  return hp_regen;
}

query_ep_regen() {
  return ep_regen;
}

query_race_exp_rate() {
  return race_exp_rate;
}

query_exp_rate() {
  return exp_rate;
}

query_stat_percent(string arg) {
  return stat_percent[arg];
}

add_pros(i, stat) {
    if (previous_object() && interactive(previous_object()) &&
	previous_object()->query_wiz() != 5) {
	log_file("ILLEGAL_STATS", previous_object()->query_name() +
	   " tried to add "+i+" "+stat+" to "+
	   this_object()->query_name()+"\n");
	return 1;
    }
    stat_percent[stat] += i;
    if (stat == "exp_rate") {
   	 exp_rate += i;
    }
    if (stat == "skill_max") {
   	 skill_max += i;
    }
    if (stat == "spell_max") {
   	 spell_max += i;
    }
}

fix_stats() {
    this_object()->update_stats();
    write("Stats updated.\n");
    return 1;
}

query_race() {
    return race_name;
}

query_max_stat(stat) {
    return stat_max[stat];
}

set_trait(num) {
  if (traits[num]) { traits[num] = 0; return 0; }
  traits[num] = 1;
  return 1;
}

query_traits(num) {
  return traits[num];
}

reset_traits() {
  stat_trait = ([ ]);
  traits = ([ ]);
}

set_stat_trait(stat, num) {
  stat_trait[stat] += num;
  return stat_trait[stat];
}

query_stat_trait(stat) {
  return stat_trait[stat];
}

update_race(str,m_str,m_dex,m_con,m_int,m_wis,m_size,rate,skill_m,spell_m,spe,hpregen,spregen,epregen) {
  if (guest) { return; }
  race_name = str;
  stat_max["str"] = m_str;
  stat_max["dex"] = m_dex;
  stat_max["con"] = m_con;
  stat_max["int"] = m_int;
  stat_max["wis"] = m_wis;
  stat_max["size"] = m_size;
    race_exp_rate = rate;
    skill_max = skill_m;
    spell_max = spell_m;
    base_hp_regen = hpregen;
    base_sp_regen = spregen;
    base_ep_regen = epregen;
    this_object()->update_stats();
}

set_race(str,m_str,m_dex,m_con,m_int,m_wis,m_size,rate,skill_m,spell_m,spe,hpregen,spregen,epregen) {
  if (guest) { return; }
  update_race(str,m_str,m_dex,m_con,m_int,m_wis,m_size,rate,skill_m,spell_m,spe,hpregen,spregen,epregen);
  stat_percent["str"] = 20;
  stat_percent["dex"] = 20;
  stat_percent["con"] = 20;
  stat_percent["int"] = 20;
  stat_percent["wis"] = 20;
  size = stat_max["size"] / 2;
  this_object()->update_stats();
}

exps() {
    int i, a, next_level, str1, str2, str3, str4, str5, str6,str7;
    string level_tmp, str;
    if (query_free_exp() && query_free_exp() != "0") {
 	write("Free experience left: "+query_free_exp() +"\n");
    }
write("+-----------------------+--------------------+-----------+-----------+\n");
write("|Skill name:            |  Exp to next step  |  Current  |Training to|\n");
write("+-----------------------+--------------------+-----------+-----------+\n");
    while (i < 10) {
	if (skill_train[i]) {
	    str = "";
	    if (strlen(("|"+skill_train[i])) < 8) { str = "\t"; }
	    if (strlen(("|"+skill_train[i])) < 16) { str = str + "\t"; }
	    if (strlen(("|"+skill_train[i])) < 26) { str = str + "\t"; }
	    str3 = call_other("/guilds/obj/skillpros","pros_names",
		(skill_left[i]+skills[skill_train[i]]));
	    str7 = call_other("/guilds/obj/skillpros", "pros_names",
		skills[skill_train[i]]);
	}
	if (skill_train[i]) {
	  write("|" + capitalize(skill_train[i]) + str + "|"+
	  write_palkki(skill_exps[i], skill_costs[i],19)+"|"+str7+"|"+ str3+"|\n");
	  if (tester)
	    write(skill_exps[i]+"/"+skill_costs[i]+"\n");
	  a += 1;
	}
	i += 1;
    }
    if (!a) {
      write("|You are not training anything just now.                             |\n"); 
    }
    if (!level_cost) {
      write("+-----------------------+--------------------+-----------+-----------+\n");
    } else {
      write("+-----------------------+---+----------------+-------+---+-----------+\n");
      write("|Level advancement:         |   Experience needed    |\n");
      write("+---------------------------+------------------------+\n");
	next_level = level + 1;
	str2 = extract(level_name,0,25);
	str2 = capitalize(str2);
	str3 = write_palkki(level_exp, level_cost,23);
	str2 = str2+ get_spaces(str2,26);
	if (tester)
	  write("Debug: level_exp: "+level_exp+", cost:"+level_cost+"\n");
	write("|"+ str2 + "|"+str3+"|\n");
	write("+---------------------------+------------------------+\n");
    }
}

write_palkki(int exp, int cost, int max_strlen) {
  string str, palkit, tyhjat;
  int max, current,tmp,i;
  str = ""+cost;
  tmp = 1;
  /* tmp = 10^(strlen(str)-1) */
  while(i < strlen(str)-1) {
    tmp = tmp * 10;
    i += 1;
  }
  tmp = cost / tmp;
  max = strlen(str) * 2;
  if(tmp > 4) max += 1;
  /* if max*exp > integer_max => visual bug //Celtron */
  if(exp > 100000000)
    current = ((exp/1000) * max / (cost/1000));
  else
    current = (max * exp) / cost;

  palkit = "###############################################################################";
  tyhjat = "...............................................................................";

  if (current) { palkit = extract(palkit, 1, current); }
  else { palkit = ""; }
  if (max-current) { tyhjat = extract(tyhjat, 1, (max-current)); }
  else { tyhjat = ""; }
  palkit = "["+palkit+tyhjat+"]";
  if(max_strlen) palkit = palkit+get_spaces(palkit,max_strlen);
  return palkit;
}

get_spaces(arg, int max) {
    int i;
    string str,num,tmp;
    num = arg+"";
    tmp = "                                   ";
    if(strlen(num) <= max) {
      str = extract(tmp,0,max-strlen(num));
    } else {
      str = "";
    }
    return str;
}

/* num must be seconds */
string stime(int i) {
  string str; str = "";
  if(i/86400) {
    str+=i/86400+"d ";
    i -= (i/86400)*86400;
  }
  if(i/3600) {
    str+=i/3600+"h ";
    i -= (i/3600)*3600;
  }
  if(i/60) {
    str+=i/60+"m ";
    i -= (i/60)*60;
  }
  str+=i+"s";
  return str;
}

add_task_points(i) {
  if (!this_player()) { return; }
  if (this_player()->query_real_name() != "onarion" &&
     this_player()->query_real_name() != "celtron" ||
     !interactive(this_player())) {
	log_file("ILLEGAL_TP", ctime(time())+" "+
previous_object()->query_name()+" ("+file_name(previous_object())+") "+
"tried to set "+i+" illegal task points for "+this_object()->query_name()+"\n");
	return 0;
  }

  task_points += i;
  max_task_points += i;
  return task_points;
}

reset_wishes() {
  lesser_wishes = allocate(20);
  greater_wishes = allocate(20);
  task_points = max_task_points;
  lesser_number = 0;
  greater_number = 0;
  if (task_points) {
	log_file("WISHES", ctime(time())+" "+this_object()->query_name()+
		": resetted "+max_task_points+" tps.\n");
  }
}

query_lesser_wishes() { return lesser_wishes; }
query_greater_wishes() { return greater_wishes; }

remove_task_points(i) {
  task_points -= i;
  max_task_points -= i;
  log_file("WISHES", ctime(time())+" "+this_object()->query_name()+
	": removed "+i+" tps.\n");
}

reduce_task_points(i) {
  task_points -= i;
  log_file("WISHES", ctime(time())+" "+this_object()->query_name()+
	": reduced "+i+" tps.\n");
}

query_task_points() { return task_points; }

query_max_task_points() { return max_task_points; }

set_lesser_wish(num) {
  if (!lesser_wishes) { lesser_wishes = allocate(20); }
/*  if (!lesser_wishes[num]) lesser_number += 1; //Celtron */
  lesser_wishes[num] = 1;
  lesser_number += 1;
  log_file("WISHES", ctime(time())+" "+this_object()->query_name()+
	" bought lesser wish number "+num+".\n");
}

set_greater_wish(num) {
  if (!greater_wishes) { greater_wishes = allocate(20); }
/*  if (!greater_wishes[num]) greater_number += 1;  hus //Celtron */
  greater_wishes[num] = 1;
  greater_number += 1;
  log_file("WISHES", ctime(time())+" "+this_object()->query_name()+
	" bought greater wish number "+num+".\n");
}

query_lesser_wish(num) {
  if (!num) { return lesser_number; }
  if (!lesser_wishes) { return; }
  return lesser_wishes[num];
}

query_greater_wish(num) {
  if (!num) { return greater_number; }
  if (!greater_wishes) { return; }
  return greater_wishes[num];
}

query_max_level() {
   if (Wiza) { return 1000; }
   /* +50 max level for less inconvenience 5.3.2003 // Celtron */
   return max_level+50;
}

add_max_level(int i) {
   if (max_level >= MAX_LEVEL) { return 0; }
   max_level += i;
   log_file("MAX_LEVEL_ADDED", ctime(time())+", "+this_player()->query_name()+" added "+i+"("+max_level+
	") max_levels for "+query_name()+".\n");
   return 1;
}

set_level_advance(cost,exp,guild_num,guild_name, lev_bonus) {
    if (level_guild) {
	return 0;
    }
    level_cost = cost;
    level_exp = exp;
    level_guild = guild_num;
    level_name = guild_name;
    level_bonus = lev_bonus;
    return 1;
}

query_skill_left(num) {
    int i;
    while(i < 10) {
	if (skill_train[i] == num) {
	     return skill_left[i];
	}             
	i += 1;
    }
    return 0;
}

query_skill_teach(num) {
    int i;
    while(i < 10) {
        if (skill_train[i] == num) {
             return skill_teach[i];
        }
        i += 1;
    }
    return 0;
}

/* teach: set_skill_train(skill_name, (student_max - student_skill), 0, 1); */
set_skill_train(string skill_num, int much, int exp, int teach) {
  int i, base_cost, skill_category, skill_pros;

  base_cost = call_other(SKILLFUN, "skill_costs", skill_num, 0, "base_cost");
  while (i < 10) {
	if (skill_train[i] == skill_num) {
	     if (much) {
		skill_left[i] += much;
	     }
	     else {
		skill_left[i] += 1;
	     }
	// mikas tama on, etta jos exps kasvaa  niin skill_left myos?? ++Celtron
	     skill_exps[i] += exp;
	     return 1;
	}
	i += 1;
  }    
  i = 0;
  skill_category = SKILLFUN->skill_costs( skill_num, 0, 0, 1, this_object());
  skill_pros = query_skills(skill_num);
  if(!skill_pros) skill_pros = 1;
  while (i < 10) {    
    if (!skill_train[i]) {
     skill_train[i] = skill_num;
     skill_costs[i] = call_other(SKILLFUN, "skill_costs", skill_train[i], skill_pros, 0, 0, this_object());
     if (teach) { skill_costs[i] = skill_costs[i] / 2; }
     if (!skill_costs[i]) { skill_costs[i] = 1; }
     skill_teach[i] = teach;
     // overtrain eli race_maxin yli
     if(skill_category == 1 || skill_category == 2) {
       if (skill_pros >= query_skill_max(base_cost)) {
 	 skill_costs[i] = skill_costs[i] * (( skill_pros - query_skill_max(base_cost))/3 +2);
       }
     }
     if(skill_category == 3 || skill_category == 4) {
        if (skill_pros >= query_spell_max(base_cost)) {
	   skill_costs[i] = skill_costs[i] * (( skill_pros - query_spell_max(base_cost))/3 +2);
	}
     }
     if (much) {
	skill_left[i] = much;
     } else {
	skill_left[i] = 1;
     }
     skill_exps[i] += exp;
     return 1;
    }
    i += 1;
  }
}

clear_level_advance() {
    level_cost = 0;
    level_exp = 0;
    level_guild = 0;
    level_name = 0;
    level_bonus = 0;
}

query_level_advance() {
   if (!level_cost) { level_name = 0; }
   return level_name;
}

remove_skill_train(string str) {
  int i;
  if(!str) {
   skill_train = allocate(10);
   skill_costs = allocate(10);
   skill_exps = allocate(10);
   skill_left = allocate(10);
  return 1;
  }
  while(i<sizeof(skill_train)) {
    if(skill_train[i] == str) {
      skill_train[i] = 0;
      skill_costs[i] = 0;
      skill_exps[i] = 0;
      skill_left[i] = 0;
      write("Skill train removed.\n");
      return 1;
    }
    i += 1;
  }    
  write("You are not training such a skill.\n");
  return 1;
}


clear_skill_train(int num) {
    int i, base_cost, skill_type;
    base_cost = call_other(SKILLFUN, "skill_costs", 
		skill_train[num], 0, "base_cost", 0, this_object());
    if (skill_left[num] == 1) {
	skill_train[num] = 0;
	skill_costs[num] = 0;
	skill_exps[num] = 0;
	skill_left[num] = 0;
	return 1;
    }
    else {
	skill_exps[num] = 0;
	skill_costs[num] = SKILLFUN->skill_costs( skill_train[num], query_skills(skill_train[num]), 0, 0, this_object());
	skill_type = SKILLFUN->skill_costs( skill_train[num], 0, 0, 1, this_object());

        if(skill_type == 1 || skill_type == 2) {
             if (query_skills(skill_train[num]) >= query_skill_max(base_cost)) {
                skill_costs[num] = skill_costs[num] *
((query_skills(skill_train[num]) - query_skill_max(base_cost))/3+2);
             }
	}
        if(skill_type == 3 || skill_type == 4) {
             if (query_skills(skill_train[num]) >= query_spell_max(base_cost)) {
                skill_costs[num] = skill_costs[num] *
((query_skills(skill_train[num]) - query_spell_max(base_cost))/3+2);
             }
	}
	if (skill_teach[num]) { skill_costs[num] = skill_costs[num] / 2; }
	skill_left[num] -= 1;
	return 1;
    }
}

add_skill_exps(int num,setti) {
    int i, a, exp, trained_now;
    while (i < 10) {
	if (skill_train[i]) { 
	     a += 1;
	}
	i += 1;
    }  
    if (level_cost) {
	a += 1;
    }
    i = 0;
    if (!a) {
      if(!setti) { add_total_worth(num / 2); }
      return num;
    }
    exp = num / a;
    while (i < 10) {
	if (skill_train[i]) {
		skill_exps[i] += exp;
	}
	if (skill_exps[i] >= skill_costs[i] && skill_train[i]) {
		int over;
		advance_skill(skill_train[i], 1);
		over += skill_exps[i] - skill_costs[i];
		add_total_worth(skill_costs[i]);
		clear_skill_train(i);
		skill_trained += 1;
		trained_now += 1;
		if (trained_now == 1) {
		    tell_object(this_object(),"You feel you understood something more about your skills.\n");
		}       
	}
	i += 1;
    }
    if (level_cost) {
	level_exp += exp;
	if (level_exp >= level_cost) {
	     advance_guild_level(level_guild);
             this_object()->add_total_worth(level_cost);
	     over += level_exp - level_cost;
     	     GUILD->starter_guild_advance(level_name, starter_guild, this_object());
	     clear_level_advance();
	     tell_object(this_object(), "You feel somewhat more advanced in your guild.\n");
	     tell_object(this_object(), "New stats are: Str " + c_str + " Dex " + c_dex + " Con " +
		    c_con + " Int " + c_int + " Wis " + c_wis + ".\n");
             save_me(1);
	}
    }
    if (over && skill_trained > 10) {
	skill_trained = 0;
	call_out("add_skill_exps", 0, over);
        log_file("OVER_TRAIN", ctime(time())+" "+query_name()+" has "+over+" over! (necro "+this_object()->query_guild_level("Necromancers") +")\n", 1);
	return;
    }
    if (over && skill_trained < 11) {
	add_skill_exps(over);
	return;
    }
}
static add_experience(exp,string str) {
  int tmp,tmp2,i,mega;
  string temp,temp2;
  if(str && strlen(str) > 8) {
    temp = extract(str,strlen(str)-8,strlen(str));
    temp2 = extract(str,0,strlen(str)-9);
  } else if(str) {
    temp = extract(str,0,strlen(str));
  }
  if(temp) sscanf(temp,"%d",tmp);
  if(temp2) sscanf(temp2,"%d",tmp2);
  mega = 100000000; /* 100 megaa */
  if(exp/mega) {
    tmp2 += exp/mega;
    exp -= exp/mega*mega;
  }
  tmp += exp;
  if(tmp/mega) {
    tmp2 += tmp/mega;
    tmp -= tmp/mega*mega;
  }
  temp = tmp+"";
  temp2 = tmp2+"";
  if(tmp2 != 0 && strlen(temp) < 8) {
    temp = extract("0000000000",0,7-strlen(temp)) + temp;
  }
  if(tmp2 == 0) temp2 = "";
  str = temp2+""+temp;
  return str;
}

reset_totals() {
  totals = "0";
}

reset_free_exp() {
  free_exp = "0";
}

add_free_exp(exp) {
  if(exp > 1000000000) return;
  if(intp(free_exp)) free_exp = free_exp+"";
  free_exp = add_experience(exp,free_exp);
  return free_exp;
}

query_enough_exp(int exp) {
  int tmp,tmp2,i,rest;
  string temp,temp2,str;
  str = free_exp;
  if(intp(str)) str = ""+str;
  if(str && strlen(str) > 8) {
    temp = extract(str,strlen(str)-8,strlen(str));
    temp2 = extract(str,0,strlen(str)-9);
  } else if(str) {
    temp = extract(str,0,strlen(str));
  } else if(!exp) {
    tell_object(this_object(), "Error in query_enough_exp\n");
    return 1;
  }
  if(temp) sscanf(temp,"%d",tmp);
  if(temp2) sscanf(temp2,"%d",tmp2);
   /*
  if(exp/100000000) {
    rest = tmp2;
    tmp2 -= exp/100000000;
    exp -= exp/100000000*100000000;
  }
   */
  if(tmp2 < 0) {
    return rest*100000000+tmp;
  }
  while(tmp < exp) {
    if(tmp2 > 0) {
      tmp2 -= 1;
      tmp += 100000000;
    } else {
      return (tmp);
    }
  }
  return exp;
}

/* reduces total with percent, returns new total */
reduce_by_percent(string total, int percent) {
  int last, l;
  if(percent >= 100) return 0;
  l = strlen(total);
  if(l < 7) {
    last = to_int(total);
    last -= last /100 * percent;
    total = to_string(last);
    return total;
  }
  /* hard case. only 5 first numbers matter */
 
  last = to_int(total[0..4]);
  last -= last * percent / 100;
  total = to_string(last)+total[5..l];
  return total;
}

reduce_free_exp(int exp) {
  if(exp > 1000000000) return; /* 100M */
  free_exp = reduce_experience(exp, to_string(free_exp));
  return free_exp;
}

reduce_total_worth(int exp) {
  if(exp > 1000000000) return; /* 100M */
  totals = reduce_experience(exp, to_string(totals));
  return totals;
}

add_total_worth(exp) {
  if(exp > 1000000000) return;
  if(intp(totals)) totals = totals+"";
  totals = add_experience(exp,totals);
  return totals;
}

query_total_string() {
  return totals;
}

query_free_exp() {
  return free_exp;
}

static add_worth_to_free_exp() {
  string tmp, alku, loppu;
  int i, i_alku;
  tmp = totals;
/* By Onarion, 7.2.1999, trying to prevent sscanf(tmp, "%d".. from bugging occationnally */
  if (!tmp) { return; }
  if(strlen(tmp) < 10) {
    if(!sscanf(tmp, "%d", i)) {
      write("Error occured while converting worth.\n");
      return 1;
    }
    add_free_exp(i);
    totals = "0";
    return 1;
  }
  i = 0;
  i = strlen(tmp);
  alku = extract(tmp, 0,i-10);
  loppu = extract(tmp,i-9,i-1);
  write(alku+"G "+loppu+"\n");
  if(strlen(alku) > 9) {
    write("Cannot convert worth to free exp.\n");
    return 0;
  }
  if(sscanf(alku, "%d", i_alku) != 1) {
    write("Error in converting exp.\n");
    return 0;
  }
  if(sscanf(loppu, "%d", i) == 1) {
    add_free_exp(i);
  }
  while(i_alku > 0) {
    add_free_exp(1000000000);
    i_alku -= 1;
  }
  totals = "0";
  return 1;
}

/* exp is the amount of being reduced from str */
static reduce_experience(int exp,string str) {
  int tmp,tmp2,i,mega;
  string temp,temp2;
  if(intp(str)) str = to_string(str);
  /* 100M >= */
  if(str && strlen(str) > 8) {
    /* 9 876 543 210 */
    temp = extract(str,strlen(str)-8, strlen(str));
    temp2 = extract(str,0,strlen(str)-9);
  } else if(str) {
    temp = extract(str,0,strlen(str));
  } else {
    tell_object(this_object(), "Error in reduce_total_worth\n");
    return 1;
  }
  if(temp) tmp = to_int(temp);
  if(temp2) tmp2 = to_int(temp2);
  mega = 100000000; /* 100 megaa */
  /* reduce 100M bulks */
  if(exp/mega) {
    tmp2 -= exp/mega;
    exp -= exp/mega*mega;
  }
  tmp -= exp;
  if(tmp < 0 && tmp2 > 0) {
    tmp2 -= 1;
    tmp += mega;
  }
  if(tmp <0) tmp = 0;
  if(tmp2<0) {
        tmp2 = 0;
	log_file("REDUCE_EXPERIENCE", ctime(time())+" "+query_name()+" negative value\n");
  }
  temp = to_string(tmp);
  temp2 = to_string(tmp2);
  if(tmp2 != 0 && strlen(temp) < 8) {
    temp = extract("0000000000",0,7-strlen(temp)) + temp;
  }
  if(tmp2 == 0) temp2 = "";
  str = temp2+""+temp;
  return str;
}

/* turns this_object() as a wizard */
wiz_me() {
  if(this_player()->query_wiz() != 5 || this_player()->query_name() != "Celtron" &&
     this_player()->query_name() != "Nalle" || 	!interactive(this_player())) {
     return;
  }
  log_file("NEW_WIZ", ctime(time())+": "+this_player()->query_name()+" wizzed "+cap_name+".\n");
  Wiza = 1;
  level = 100;
  set_wiz_short("s");
  save_me();
  tell_object(this_object(), "You are now a wizard, please re-enter.\n");
  destruct(this_object());
}

query_see_invisible() {
  if(query_wiz()) return 10;
}

query_clan() {
  return clan;
}

set_clan(string str) {
  clan = str;
}

short() {
  string tmp, pname, clandesc;
  if (guest)
	return capitalize(name)+ " the Visitor";
  if (ghost)
	return "ghost of " + cap_name;
  if(query_invisible() && query_wiz() < query_wiz()) return;
  if (wiz_short && wiz_short != "") { return wiz_short; }
  if (set_short && set_short != "") { return set_short; }

  pname = "";
    
  if (query_party()) { pname = " <" + query_party()->query_party_name() + ">"; }

  if(!title) title = GUILDRANK_D->query_highest_rank(this_object());
  tmp = "";
  if(title) {
    tmp = " " + title;
  }
  clandesc = "";
/*
  if(clan) {
    clandesc = " {"+capitalize(clan)+"} ";
  }
*/
  if (!race_name) { return capitalize(name); }
  if(!surname || surname == "") {
    return capitalize(name)+ " the " + capitalize(race_name) + tmp + clandesc + pname;
  }
  return capitalize(name) + " " + capitalize(surname) + " the " + capitalize(race_name) + tmp + clandesc + pname;
}


/*********************************************/

// Move this to an inherited thing at some point

long() {  
    string cap_pronoun,temp;
    cap_pronoun = capitalize(query_pronoun());
    write(short() + "\n");
    if (ghost) return;

    // Show race
    temp=query_race();
    if(frog) temp="frog";
    if(query_wiz()) temp="Coder";
    if(query_tester()) temp="tester";
    write(cap_pronoun+" is member of the "+temp+" race.\n");

    // Show align is good enough cast alignment

    // Approximate for +30
    if	(
	 (this_player()->query_skills("cast alignment") > 30) &&
	 (this_player()->query_skills("cast alignment") < 90)
	)
	{
	switch(query_alignment()) 
	 {
	  case 50..300 : 
		write(cap_pronoun+" is of a good alignment.\n");
		break;
	  case -49..49 : 
		write(cap_pronoun+" is of a neutral alignment.\n");
		break;
	  case -300..-50 :
		write(cap_pronoun+" is of an evil alignment.\n");
		break;
	 }
	}
    
    // Detailed align info for +90
    if( this_player()->query_skills("cast alignment") >= 90)
	{
        string t;
	switch(query_alignment()) 
		{
		case 100..300:
        			t = "an extremely good"; break;
		case 50..99:
        			t = "a good"; 		break;
		case 10..49:
				t = "a slightly good"; 	break;
		case -9..9:
				t = "a neutral"; 	break;
		case -49..-10:
				t = "a slightly evil";	break;
		case -99..-50:
        			t = "an evil";		break;
		case -300..-100:
				t = "an extremely evil"; break;
    		default:
  		}

	write( "You consider "+query_objective()+" a creature of "+
		t+" alignment.\n");
	}

    show_scar();
}

/*********************************************/

query_skill_map() {
  return skills;
}

query_learn_map() {
  return skill_learn;
}

write_error_log(arg) {
  object env, pre;
  string str, str2;
  if(query_wiz()) return;

  env = environment(this_object());
  if(env) str = file_name(env);
  pre = previous_object();
  if(pre) str2 = file_name(pre);
  log_file("BUG_ERROR", ctime(time())[4..15]+" ["+query_real_name()+"] (env:"+str+") [cmd:"+last_command+"] "+arg);
}

/* Identify ourself. */
id(str, lvl) {
  if(query_invisible() && this_player()->query_wiz() < query_wiz()) return;
  if (str == name) return 1;
  if (ghost) return str == "ghost of " + name;
  return 0;
}

query_title() { return title; }

/**** New invisibility code. -N	****/

query_invisible() 
{ 
 return INVISIBILITY_D->is_invis(this_player(),this_object(),invisible); 
}

query_invisibility_level() { return invisible; }

set_invisible(int i) { invisible=i; }

/***********************************/

set_level(lev) {
    if(Wiza && Wiza != 5 && this_player()->query_wiz() != 5) {
      log_file("ILLEGAL_LEVEL","Attempt to: "+cap_name+" by "+
	this_player()->query_name()+" with level "+lev+".\n");
      return 0;
    }
    level = lev;
    return 1;
}

set_surname(s) {
  if (!s) {
    write("Usage: surname <string>\n");
    return 1;
  }
  if(strlen(s) > 10 && ( this_player()->query_wiz() != 5 ) ) {
    write("Max length 10 chars.\n");
    return 1;
  }
  if (s == "clear") {
    write("Surname cleared.\n");
    surname = 0;
    return 1;
  }

  if("/daemons/editor"->ansi_check(s)) {
    write("Ansi code detected. Aborted.\n");
    return 1;
  }

  if(this_player()->query_wiz() < 4)
	surname = capitalize(lower_case(s));
	 else
	surname = s;

  return 1;
}

set_wiz_short(str) {
  if(Wiza < 3) {
    wiz_short = cap_name;
    return 0;
  }
  if (!str) {
    write("Usage: short <string>\n");
    return 1;
  }
  if (str == "clear") {
    write("Short desc cleared.\n");
    wiz_short = "";
    return 1;
  }
  wiz_short = str;
  return 1;
}

set_short(str) {
  return 0;
  set_short = str;
}

set_tester(i) {
  if(this_player()->query_wiz() < 3) { return 0; }
  tester=i;
}
query_tester() {
  return tester;
}

make_tester(str) {
  string joku,tmp;
  object ob;
  if(!str) {
    write("Usage: tester [make] <player> \n");
    return 1;
  }
  if(this_player()->query_wiz() < 3) { return 0; }
  if(sscanf(str,"make %s",joku) == 1) {
    ob=find_player(joku);
    if(!ob) {
	write("No such a player.\n");
	return 1;
    }
    ob->set_tester(1);
    write(ob->query_name()+" is now an official test character.\n");
    return 1;
  }
  if(Wiza < 4) { return 1; }
  ob = find_player(str);
  if(!ob) {
    write("No such a player.\n");
    return 1; 
  }
  ob->set_tester(0);
  write(ob->query_name()+" is no more an official test character.\n");
  return 1;
}

set_wiza(string arg) {
  int str;
  if(sscanf(arg, "%s %s", arg, str) == 2) {
    find_player(arg)->set_wiz(str);
    write("executed.\n");
    return 1;
  }
}

static wiz_commands2() {
    if (this_object() != this_player())
	return;
    if(query_wiz() > 3) add_action("set_wiza", "set_wiza");
    add_action("make_tester", "tester");
    add_action("makedir", "mkdir");
    add_action("removedir", "rmdir");
    add_action("pwd", "pwd");
    add_action("more", "more");
    add_action("echo_to", "echoto");
    add_action("set_wiz_short", "short");
    add_action("echo", "echo");
    add_action("echo_all", "echoall");
    add_action("home", "home");
    add_action("remove_file", "rm");
    add_action("cat_file", "cat");
    add_action("edit", "ed");
    add_action("destruct_local_object", "destruct");
    add_action("tail_file", "tail");
}

static wiz_commands() {
    if (this_object() != this_player())
	return;
    add_action("local_commands", "localcmd");
    add_action("force_player", "force");
    add_action("spell_zap", "zap");
    add_action("in_room", "in");
    add_action("setmmin", "setmmin");
    add_action("setmmout", "setmmout");
    add_action("setmin", "setmin");
    add_action("setmout", "setmout");
    add_action("review", "review");
}

static string gTellstring;
filter_tell() {
    int i;
    i = sizeof(users());
    while(i) {
	i = i - 1;
	if (users()[i] != this_player())
	     users()[i]->catch_shout(gTellstring);
    }
    return 1;
}

catch_shout(str) {
    tell_object(this_object(),str);
    return 1;
}

static echo_all(str) {
    if (!str) {
       write("Echoall what?\n");
       return 1;
    }
    SHOUT(str + "\n");
    write("You echo: " + str + "\n");
    return 1;
}

static echo(str) {
    if (!str) {
       write ("Echo what?\n");
       return 1;
    }
    say (str + "\n");
    write ("You echo: " + str + "\n");
    return 1;
}

static echo_to(str)
{
    object ob;
    string who;
    string msg;
    if (!str || sscanf(str, "%s %s", who, msg) != 2) {
	write("Echoto what ?\n");
	return 1;
    }
    ob = find_living(lower_case(who));
    if (!ob) {
	write("No player with that name.\n");
	return 1;
    }
    tell_object(ob, msg + "\n");
    write("You echo: " + msg + "\n");
    return 1;
}

quit() {
  object ob;
  if (!check_condis()) { return -1; }
  if(attacker_ob && environment(attacker_ob) == environment(this_object()) ) {
    write("You cannot quit while in combat.\n");
    return -1;
  }
  keep("clear");
  enter_time = time();
  recovery_load = "";
  write("Saving "); write(capitalize(name)); write(".\n");
  save_me(0); /* nollalla ei pista recoverya */
  /* ei droppaa autoload kamoja (destaa ne) */
  call_other("/cmds/std/_drop", "cmd_drop", "all", this_object());
  ob = query_party();
  if (ob) {
    ob->remove_party_member(this_object());
  }
  say(cap_name + " left the game.\n");
  write("Updating plaque..");
  find_object(CHANNEL_D)->send_to_channel("inform", cap_name+" left the game.");
  destruct(this_object());
  return 1;
}

/* arg == ??, when force == 1, force link death */
link_death(mixed arg, status force) {
  object ob;
  if(query_guest()) {
    write("Leaving game..\n"); 
    return quit();
  }
  if(force) {
   if(interactive(this_object()) && arg) return;
   if(this_object()->query_link_dead()) return;
   if(interactive(this_object()) && !arg) {
     if(!check_condis()) { return 1; }
     if(dead || ghost) {
       return;
     }
   }
  }
  /* celtron 06. 02. 99 */
  if(attacker_ob) hit_point = 1;
  link_dead = 1;
  time_ld = time();
  save_me(1);
  ob = present("party object",this_player());
  if (ob) {
     ob->change_leader_to_next(this_object());
  }
  say(cap_name + " goes link dead.\n");
  ld_location = environment(this_object());
  if(interactive(this_object())) { remove_interactive(this_object()); }
  set_heart_beat(0);
  move_object(this_object(), "/world/special/ldroom");
  find_object(CHANNEL_D)->send_to_channel("inform", cap_name+" goes link dead.");
  return 1;
}

kill(string str) {
    object ob;
    if(query_guest()) {
      write("Guests cannot engage combat.\n");
      return 1;
    }
    if (!check_condis()) { return 1; }
    if (!str) {
	write("Kill what ?\n");
	return 1;
    }
    if (environment()->query_property("no_kill")) {
      write("A mysterious force stops you.\n");
      return 1;
    }
    ob = present(lower_case(str), environment(this_player()));
    if (!ob) {
	write("No " + str + " here !\n");
	return 1;
    }
    if (!living(ob)) {
	write(capitalize(str) + " is not a living thing!\n");
	return 1;
    }
    if (ob == this_object()) {
	write("What? Attack yourself?\n");
	return 1;
    }
    if (attacker_ob == ob) {
	write("You are already fighting!\n");
	return 1;
    }
    say(cap_name + " attacks " + ob->query_name() + "!\n");
    attack_object(ob);
    return 1;
}

void set_say_messages(string *msg) { say_messages = msg; }
string *query_say_messages() { return say_messages; }

print_hunger() {
  if(query_hunger()*6 < query_max_hunger()) {
      tell_object(this_object(), "You are STARVING!\n");
  } else if (query_hunger()*4 < query_max_hunger()) {
      tell_object(this_object(), "You are hungry!\n");
  } else if (query_hunger()*3 < query_max_hunger()) {
      tell_object(this_object(), "You are feeling hungry.\n");
  }
  if(query_thirst()*6 < query_max_thirst()) {
      tell_object(this_object(), "You are REALLY thirsty!\n");
  } else if(query_thirst()*3 < query_max_thirst()) {      
      tell_object(this_object(), "You are thirsty!\n");
  }
}

static heart_beat() {
  int i;
  if (!interactive(this_object()) && !query_link_dead()) {
	call_out("link_death",6,1);
  }
  if (query_ghost() || query_link_dead()) return 0;
  if (interactive(this_object())) {
    age += 1;
    if(query_idle(this_object()) < 300)
      real_age += 1;
  }
  if (age > time_to_save) {
    if (!brief)
	    write("Autosave.\n");
    if(!query_wiz()) {
      write("Adding exp for age.\n");
      add_party_exp(query_level()*400,0,0,1); /* nontunexp */
  //  add_exp(query_level()*400); /* testing by nalle */
    }
    save_me(1);
    time_to_save = age + 30*60;
  }
  if (size < stat_max["size"]) {
     time_for_growth += 1;
     if (random(1000) < time_for_growth) {
       write("You grow a bit.\n");
       time_for_growth = 0;
       set_size(size + 1);
     }
  }
  if (!Wiza && !random(2)) {
    add_hunger(1);
    add_thirst(1);
  }
  if(death_legacy_time > 0) {
    death_legacy_time -= 2;
    STAT_D->update_points(this_object());
  }
  if(death_legacy_time < 0) death_legacy_time = 0; /* idiot proof */

  // regen in combat possible only for rebirth chars

  if (!attacker_ob || query_rebirth()) {
      if (hit_point < max_hp || spell_points < max_sp ||
	  endurance_points < max_ep || uncon) {
	  time_to_heal -= 2;
	  if (time_to_heal <= 0 && level != 0) {
		print_hunger();
	      if(query_hunger()*3 >= query_max_hunger() &&
		query_thirst()*6 >= query_max_thirst()) {

	        if (!this_player()->query_resist_heal()) {
		  if (hit_point < max_hp) hit_point += hp_regen;
		}
	        if (hit_point > max_hp) hit_point = max_hp;

	        if (endurance_points < max_ep) endurance_points += ep_regen;
	        if (endurance_points > max_ep) endurance_points = max_ep;

	        if (spell_points < max_sp && endurance_points > 0)
			spell_points += sp_regen;
	        if (spell_points > max_sp) spell_points = max_sp;
	      }	else {
		endurance_points += 30;
		if(endurance_points > max_ep) endurance_points = max_ep;
	      }
	      if (uncon && endurance_points > 0) {
		  write("You awaken from unconciousness.\n");
		  uncon = 0;
	      }
	 time_to_heal = REGEN_TIME; /*secs*/
	 update_alignment();
	 }
      }
    }
    if (attacker_ob)
	this_object()->restore_time_points();
    if (attacker_ob && whimpy && hit_point < (max_hp*whimpy)/100)
	run_away();
    if (race_name == "drow" && !environment(this_object())->query_not_out() &&
	   set_light(0) > 2 && !random(10) &&
	   call_other("obj/timer", "get_time_of_day", 0) == 1) {
	write("The sunlight ");
 	lited("HURTS");
 	write(" your eyes!\n");
	reduce_hp(random(40));
    }

    if (sc_on && last_hp != hit_point || last_sp != spell_points || last_ep != endurance_points) {
	sc();
    }
    parse_prompt(prom);
    this_object()->shadow_heart_beat();
    last_hp = hit_point;
    last_sp = spell_points;
    last_ep = endurance_points;    
}
/* 2000 */

string set_prom(string str) { return prom = str; }
string query_prom() { return prom; }

string parse_prompt(string msg) {
  object TP,ob;
  string rest;
  TP = this_object();
  if(!msg) {
     if (!prom) { msg = ">"; }
     else { msg = prom; }
  }
  while(sscanf(msg,"%s$hp%s", msg, rest))   msg += TP -> query_hp() + rest;
  while(sscanf(msg,"%s$sp%s", msg, rest))   msg += TP -> query_sp() + rest;
  while(sscanf(msg,"%s$maxsp%s", msg, rest))   msg += TP -> query_max_sp() + rest;
  while(sscanf(msg,"%s$maxhp%s", msg, rest))   msg += TP -> query_max_hp() + rest;
  while(sscanf(msg,"%s$ep%s", msg, rest))   msg += TP -> query_ep() + rest;
  while(sscanf(msg,"%s$maxep%s", msg, rest))   msg += TP -> query_max_ep() + rest;
  while(sscanf(msg,"%s$level%s", msg, rest))   msg += TP -> level() + rest;
  while(sscanf(msg,"%s$time%s", msg, rest))   msg += ctime(time()) + rest;
  while(sscanf(msg,"%s$newline%s", msg, rest))   msg+= "\n" + rest;
  while(sscanf(msg,"%s$weight%s", msg, rest)) {
       msg += ((TP->query_local_weight()*100)/(TP->query_max_weight()));
       msg += "%" + rest;
  }
  while(sscanf(msg,"%s$mshape%s", msg, rest)) {
    if(ob = TP->query_attack()) {
    if (ob->query_hp() < ob->query_max_hp() / 8) {
        msg += "about to die" + rest;
    }
    else if (ob->query_hp() < ob->query_max_hp() / 5) {
        msg += "very bad shape" + rest;
    }
    if (ob->query_hp() < ob->query_max_hp() / 3) {
        msg += "bad shape" + rest;
    }
    if (ob->query_hp() < ob->query_max_hp() / 2) {
        msg += "injured" + rest;
    }
    if (ob->query_hp() < ob->query_max_hp() *3 /4) {
        msg += "somewhat injured" + rest;
    }
    if (ob->query_hp() < ob->query_max_hp() *4 /5) {
        msg += "slightly hurt" + rest;
    }
    if (ob->query_hp() < ob->query_max_hp()) {
        msg += "good shape" + rest;
    }
    if (ob->query_hp() == ob->query_max_hp()) {
        msg += "excellent shape" + rest;
    }
    }
  }

  while(sscanf(msg,"%s$ghost%s", msg, rest)) {
    if(TP->query_ghost()) msg += "Yes" + rest;
    else { msg += "No" + rest; }
  }

  while(sscanf(msg,"%s$safeexp%s", msg, rest)) msg += TP->query_free_exp() + rest;

  set_prompt(msg);
  return msg;
}

/*
 * Update our aligment.
 */


/* Change alignment only after a delay, and only a bit at the time..
	Onarion 28.3.98 */

update_alignment() {
    int i;
    if (!al_change) { return; }
    i = random(3) + 1;
    if (al_change < i && al_change > -i) {
	alignment += al_change;
	return 1;
    }
    if (al_change > 0) {
	alignment += i;
	al_change -= i;
    }
    if (al_change < 0) {
	alignment -= i;
	al_change += i;
    }
    if (alignment > 200) { alignment = 200; al_change = 0; }
    if (alignment < -200) { alignment = -200; al_change = 0; }
    return alignment;
}

query_al_change() { return al_change; }

add_alignment(a) {
    if (!intp(a)) {
	write("Bad type argument to add_alignment.\n");
	return;
    }
    al_change += a / 3;
    if (a < 0) { al_change -= 1; }
    if (a > 0) { al_change += 1; }
}

/****************************************/

int hard_add_alignment(int a)
{
alignment+=a;
if (alignment > 200) { alignment = 200; al_change = 0; }
if (alignment < -200) { alignment = -200; al_change = 0; }
}

/****************************************/

set_al(a) {
    if (!intp(a))
	return;
    alignment = a;
}

set_alignment(al) {
    al_title = al;
}

add_god_status(num) {
    god_status += num;
  if(god_status > 300) god_status = 300;
  if(god_status < -300) god_status = -300;
}

query_god_status() { return god_status; }

query_real_age() { return real_age; }

test_dark(status arg, status return_string) {
    int light_level;
    if (query_wiz() && query_name() != "Onarion" || guest) { return 3; }
    if(query_level() < 15) return 3; /* nyyppahelpotusta //Celtron */
    light_level = set_light(0);
    if(!this_player()) return 3;
    if(!environment(this_player())) {
      write("You have no environment.. transferring to inn.\n");
      move_object(this_player(), "/world/city/inn");
      return 3;
    }
    if(return_string) return find_object("obj/timer")->get_light_time(1);
    if (!environment(this_player())->query_not_out()) {
	light_level += find_object("obj/timer")->get_light_time();
    }
    if(race_name) {
      light_level += call_other("/obj/race_selection", "query_infra",race_name);
    }
    if (light_level <= 0 && !arg) {
	write("It is too dark to see.\n");
	return 0;
    }
    return light_level;
}

drop() { return 1; }

add_weight(w) {
    int max;
    max = query_max_weight();
    if (w + local_weight > max)
	return 0;
    if(w + local_weight < 0)
	return 0;
    local_weight += w;
    return 1;
}

query_max_weight() {
  return (c_str * 50 + 2000);
}

fix_weight() {
  object ob;
  ob = first_inventory(myself);
  local_weight = 0;
  if(this_object()->query_tester()) write("fix_weight() called\n");
  while(ob) {
      add_weight(call_other(ob, "query_weight"));
      ob = next_inventory(ob);
  }
  return 1;
}

shout_to_all(str) {
    if (!check_condis()) { return 1; }
    if (spell_points < max_sp || query_level() < 5) {
	write("You are low on power.\n");
	return 1;
    }
    if (!str) {
	write("Shout what ?\n");
	return 1;
    }
    if (ghost) {
	write("You are a ghost.\n");
	return 1;
    }
    if (!Wiza)
	spell_points = 0;
    if (!frog) { SHOUT(cap_name + " shouts: " + str + "\n"); }
    else {
      SHOUT(cap_name + " the frog shouts: " + "Hriibit! Hrriiibit!" + "\n");
    }
    write("You shout: " + str + "\n");
    return 1;
}

look(string str,int telep) {
  return call_other("/cmds/std/_look", "cmd_look", str, telep, this_object());
}

static check_password(p) {
    write("\n");
    remove_call_out("time_out");

    under_pwd_query = 0;

    local_weight = 0;
    armour_class = 0;
    name_of_weapon = 0;
    name_of_right_weapon = 0;
    name_of_left_weapon = 0;
    if (password == 0)
      write("You have no password ! Set it with the 'password' cmd.\n");
    else if (name != "guest" && crypt(p, password) != password) {
      write("Wrong password.\n\n");
      write("Forgot your password?\n" +
	"Mail to 'quest@quest.laeppae.com' and we will see what we can do.\n");
      write("\n[Enter] to continue.\n");
      wrong_pwd = 1;
      input_to("pause");
      return;
    }
    if((int)BANISH_D -> query_ban_name_time(lower_case(name)) > 0) {
      if((int)BANISH_D->query_ban_name_time(lower_case(name)) < time()) {
         BANISH_D->unbanish_name(lower_case(name));
      }
    }

    if(BANISH_D->check_banned_name(lower_case(name))) {
  	write("You have been banished because of '" +
  	BANISH_D -> query_reason(lower_case(name)) + "' by "+
  	BANISH_D -> query_name_banner(lower_case(name)) + ".\n");
	write("Banishment ends " +
	    ctime(BANISH_D->query_ban_name_time(lower_case(name)))+".\n");
  	destruct(this_player());
       	return 0;
    }
    move_player_to_start(0);
#ifdef LOG_ENTER
    log_file("ENTER", cap_name + ", " + extract(ctime(time()), 4, 15)+
", "+query_ip_number(this_object())+" ("+sizeof(users())+")\n");
#endif
}

/*
 * Give a new password to a player.
 */
static new_password(p) {
    int i;
    write("\n");
    if (!p || p == "") {
	write("Try again an other time then.\n");
	logon();
	return;
    }
    if (strlen(p) < 4) {
	write("The password must have at least 4 characters.\n");
	input_to("new_password", 1);
	write("Password: ");
	return;
    }
    if (password == 0) {
	password = p;
	input_to("new_password", 1);
	write("Password: (again) ");
	return;
    }
    remove_call_out("time_out");
    if (password != p) {
	write("Did not match. Try again.\n");
	name = "logon";
	password = 0;
	logon();
	return;
    }
    password = crypt(password, 0);      /* Generate new seed. */
    set_level(0);
    conversed = CONVERSE;
    set_str(5); set_con(5); set_int(5); set_dex(5); set_wis(5); set_size(5);
    hit_point = max_hp;
    i = 0;
    move_player_to_start(0);
    log_file("NEWPLAYER", ctime(time()) + " " +cap_name + " created. ("+query_ip_number(this_object())+")\n");
}

static move_player_to_start(where) {
  move_player_to_start2(where);
}

static move_player_to_start2(where) {
  if (gender == -1) {
    write("Are you [m]ale or [f]emale: ");
    input_to("getgender", 0);
    return;
  }
  move_player_to_start3(where);
}

/*  This function is called using input_to, and sets the
 *  gender of this player.
 */
static getgender(gender_string) {
  int i;
  gender_string = lower_case(gender_string);
  if (gender_string[0] == 'm') {
      write("Welcome, Sir!\n");
      set_male();
  }
  else if (gender_string[0] == 'f') {
      write("Welcome, Lady!\n");
      set_female();
  }
  else {
      write("No such gender.\n");
      write("Are you male or female (type 'm' or 'f'): ");
      input_to("getgender");
      return;
  }  

  /* Get initial max_level */
  max_level = 100;
  
 /* sc on */
  sc_on = 1;

 /* Join channel mud & inform & newbie */
  this_object()->add_channel("inform");
  this_object()->add_channel("mud");
  this_object()->add_channel("newbie");

  move_player_to_start3(saved_where);
}

query_link_dead() { return link_dead; }

string *filter_news(string *news) {
int i;
string *tmp;
tmp = ({ });
for(i=0;i<sizeof(news);i++) {
   if( ("cmds/std/_news") -> has_access(news[i])) tmp += ({ news[i], });
}
return tmp;
}

static move_player_to_start3(where) {
    object ob, quicktyper,obje;
    string tmp_name, komento, str;
string *groups;
string finalstr;
int i;
    /*
     * See if we are already playing.
     * We must blank our own name, or we could find ourselves !
     */
    tmp_name = name;
    name = 0;
    other_copy = find_player(tmp_name);
    name = tmp_name;
    if(other_copy && !other_copy->query_link_dead()) {
      other_copy->link_death(0);
/*      find_object(CHANNEL_D)->send_to_channel("inform", cap_name+" goes link dead."); */
    }
    enable_commands();

    set_command(0,0,1); /* command var resize */

    if (other_copy) {
      link_dead = 0;

     if( !query_invisibility_level() )
      find_object(CHANNEL_D)->send_to_channel("inform", cap_name+" recovers from link death.");

      tell_object(this_object(), "You recover from link death.\n");
      ob = this_object();
      exec(other_copy, ob);
      remove_interactive(ob);
      other_copy->recover_preparation(ob);
      return 1;
    }      
    /*
     * Initilize the character stats, if not already done.
     */
    set_heart_beat(1);
    add_standard_commands();
    if (Wiza >= 1) {	
	wiz_commands();
	wiz_commands2();
    }
    enter_time = time();
    if (!real_age) { real_age = age; }

  // necro bug fix aftermath conversion 
    if(conversed == 10 && !query_guild_level("Necromancers") ) conversed = 11;

    if(conversed != CONVERSE) {
	write("\nCONVERSION REINC\n");
	if (Wiza) { write("(Wizards have to converse too if they want to reinc).\n"); }
	if(ghost) remove_ghost(100, "/obj/race_selection.c");
	reinc();
 	set_race(0);
    }
    if (!query_race() || !level && !guest) {
	command("term ansi", this_object());
	move_object(myself, "/obj/race_selection");
	write("Now select your race.\n");
	write("Type 'look' ('l') to see the information again.\n");
    }     
    else {    
	this_object()->update_stats();
	if (where) {
	    move_object(myself, where);
	}
	else {
	    if (!ghost) {
		if(Wiza && file_size("/wizards/"+name+"/workroom.c") > 0) {
		  move_object(myself, "/wizards/"+name+"/workroom");
		} else {
/* starting locations */
		  if(!starting_location)
			starting_location = "/world/city/inn";
		  move_object(myself, starting_location);
		}
	    }
	    else {
		 move_object(myself, "world/special/hell");
	    }
	}
    }
    cat("/NEWS");
    while(remove_call_out("time_out") != -1) {
	remove_call_out("time_out");
    }
    set_living_name(name);
if (!guest) {
    call_other("/obj/race_selection", "update_race",race_name);
    if(LEADER_D->query_leader() == lower_case(name)) {
	move_object(clone_object("guilds/obj/leader_eq.c"), this_object());
    }

    if(!query_invisibility_level())
	say(cap_name + " enters the game.\n");

    if(query_invisibility_level())
      if(this_player()->query_wiz())
        write("\nYou are invisible! (Invisibility level "+query_invisibility_level()+")\n\n");
	else
	write("\nYou are invisible!\n\n");

    if(Wiza) { cat("/WIZNEWS"); }
    if (!ghost) call_other("world/city/post", "query_mail", 0);
    if (query_ip_number() != called_from_ip && called_from_ip)
	write("Your last login was from " + called_from_ip + "\n");
    called_from_ip = query_ip_number();
    current_path = "wizards/" + name;
}

    groups = ("daemons/news_d") -> query_groups();
    groups = filter_news(groups);
    finalstr = "Unread news: ";
for(i=0;i<sizeof(groups);i++) {
   if(!news_data && i < (sizeof(groups)-1)) {
     finalstr += groups[i]+", ";
   }
  else if(!news_data && i == sizeof(groups)-1) {
     finalstr += groups[i]+".";
  }
   else if(news_data[groups[i]] < ("daemons/news_d")->query_message_number(groups[i])) {
     if(i < (sizeof(groups)-1)) {
       finalstr += groups[i]+", ";
     } else {
       finalstr += groups[i]+".";
     }
   }
}
    if(finalstr == "Unread news: ") finalstr = "No unread news.\n";
    write(finalstr+"\n");

    if (!ghost && !guest) {
      call_other(find_object("/daemons/explist"), "update_plaque", this_object());
    }
    set_modify_command(this_player());

    load_safe_obj(safe_load);
    load_auto_obj(auto_load);
    load_recovery_obj(recovery_load);

    clan = CLAN_D->query_clan(this_object());
    if(clan) CLAN_D->clan_eq(this_object());

    this_object()->fix_quest_points();

    /* guild leadership //Celtron */
    if(level >= 30) {
      GUILDRANK_D->try_lead();
    }

   if(query_invisibility_level())
    find_object(CHANNEL_D)->send_to_channel("inform", cap_name+" enters the game.");

    update_stats();
    look();
    /* entering the game completed */
}

recover_preparation(ob) {
  set_modify_command(this_object());
  say(query_name() + " recovers from linkdeath.\n");
  if(!ld_location) {
    move_object(this_object(), "/world/city/cs");
  } else {
    move_object(this_object(), ld_location);
  }
  if (ghost) { move_object(this_object(), "/world/special/hell"); } 
  link_dead = 0;
  set_heart_beat(1);
  destruct(ob);
  return 1;
}

void restore_heart_beat() {
  set_heart_beat(1);
}

tail_file(path)
{
    if (!path)
	return 0;
    if (!tail(path))
	return 0;
    return 1;
}

cat_file(path)
{
    if (!path)
	return 0;
    if (!cat(path))
	write("No such file.\n");
    return 1;
}

static bell_delay() {
  belling = 0;
  return 1; 
}

query_starting_location() {
  return starting_location;
}

set_starting_location(string loc) {
  starting_location = loc;
}

static bell(str) {
  object ob;
  ob = find_player(str);
  if(!ob) {
    write("No such a player.\n");
    return 1;
  }
  if(belling) { write("Take a break..\n"); return 1; }
  belling = 1;
  call_out("bell_delay", 10);
  tell_object(ob, cap_name+" bells you!\n");
  write("You bell "+ob->query_name()+".\n");
  return 1;
}

query_ignore(string player) {
  return IGNORE->query_ignore(player, this_object());
}

void set_ignored(string *list) { ignored = list; }
string *query_ignored() { return ignored; }

string * set_last_tells(string *a) { return last_tells = a; }
string * query_last_tells() {
  if (!pointerp(last_tells)) { last_tells = ({}); }
  return last_tells; 
}

string set_last_msg(string x) { return last_msg = x; }
string query_last_msg() { return last_msg; }
string set_last_teller(string x) { return last_teller = x; }
string query_last_teller() { return last_teller; }


static edit(file)
{
    string tmp_file;
    if (!file) {
	ed();
	return 1;
    }
    file = (string)SIMUL->valid_write(file, this_object());
    if (!file) {
	write("You can only edit your own files.\n");
	return 1;
    }
    ed(file);
    return 1;
}

/*
 * Check that a player name is valid. Only allow
 * lowercase letters.
 */
valid_name(str)
{
    int i, length;
    if (str == "logon") {
	write("Invalid name");
	return 0;
    }
    length = strlen(str);
    if (length > 11) {
	write("Too long name.\n");
	return 0;
    }
    i=0;
    while(i<length) {
	if (str[i] < 'a' || str[i] > 'z') {
	    write("Invalid characters in name:" + str + "\n");
	    write("Character number was " + (i+1) + ".\n");
	    return 0;
	}
	i += 1;
    }
    return 1;
}

/*
 * This one is called when the player wants to change his password.
 */
static change_password(str)
{
    if (password != 0 && !str && crypt("", password) != "") {
	write("Give old password as an argument.\n");
	return 1;
    }
    if (password != 0 && password != crypt(str, password) &&
	     crypt("",password) != "") {
	write("Wrong old password.\n");
	return 1;
    }
    password2 = 0;
    input_to("change_password2", 1);
    write("New password: ");
    return 1;
}

static change_password2(str)
{
    if (!str) {
	write("Password not changed.\n");
	return;
    }
    if (password2 == 0) {
	password2 = str;
	input_to("change_password2", 1);
	write("Again: ");
	return;
    }
    if (password2 != str) {
	write("Wrong! Password not changed.\n");
	return;
    }
    password = crypt(password2, 0);     /* Generate new seed */
    password2 = 0;
    write("Password changed.\n");
}

static bug(str)
{
    if (!str) {
	write("Give an argument.\n");
	return 1;
    }
    log_file("BUGS", "\n");
    log_file("BUGS", cap_name + " (" +
	     file_name(environment(this_object())) + ", "+ctime(time())+"):\n");
    log_file("BUGS", str + "\n");
    smart_report("Bug " + cap_name + "\n" + str);
    write("Message recorded.\n");
    return 1;
}

static typo(str)
{
    if (!str) {
	write("Give an argument.\n");
	return 1;
    }
    log_file("TYPO", cap_name + " (" +
	     file_name(environment(this_object())) + "):\n");
    log_file("TYPO", str + "\n");
    smart_report("Typo " + cap_name + "\n" + str);
    write("Message recorded.\n");
    return 1;
}

static idea(str)
{
    if (!str) {
	write("Give an argument.\n");
	return 1;
    }
    log_file("IDEA", cap_name + ":\n");
    log_file("IDEA", str + "\n");
    smart_report("Idea " + cap_name + "\n" + str);
    write("Message recorded.\n");
    return 1;
}

static converse() {
    if (!check_condis()) { return 1; }
    write("Give '**' to stop.\n");
    write("]");
    input_to("converse_more");
    return 1;
}

static converse_more(str)
{
    string cmd;
    if (str == "**") {
	write("Exited.\n");
	return;
    }
    if (str[0] == '!') {
	sscanf(str, "!%s", cmd);
	command(cmd, this_object());
    } else if (str != "") {
	say(cap_name + " says '" + str + "'\n");
    }
    write("]");
    input_to("converse_more");
}

static toggle_whimpy(arg) {
    int i;
    if (!arg) {
	write("You must give percent of hp as argument.\n");
	return 1;
    }
    if (sscanf(arg, "%d", i) != 1) {
	write("You must give percent of hp as argument.\n");
	return 1;
    }
    if (i > 100) { i = 100; }
    if (i < 0) { i = 0; }
    whimpy = i;
    if (whimpy)
write("Wimpy is now "+whimpy+"%, meaning "+(query_max_hp()*whimpy/100)+" hp.\n");
    else
	write("Brave mode.\n");
    return 1;
}

query_brief() { return brief; }

toggle_brief() {
    brief = !brief;
    if (query_verb() != "brief") return brief;
    if (brief) write("Brief mode.\n");
    else write("Verbose mode.\n");
    return 1;
}

add_exp(int e,string sh, int leba) {
  object ob;
  if (query_party()) {
    query_party()->distribute_exp(e, sh, leba);
    if (sh) { query_party()->set_kills(e,sh); } /* party kills */
    return 1;
  } else if (sh) {
    set_best_kill(sh,e);
    add_kills(sh); /* query_kills */
  }
  add_party_exp(e,sh, leba);
}

/* add your own personal xp */
add_party_exp(int e, string sh, int leba, int non_tune_xp) {
    int percent, exp_tune, lvl_tmp;

  if(query_ghost()) return 0;

 /* Iffi pitaa olla ettei mee yli integer value maxin, mutta
    etta pienet expat pysyis kanssa tarkkoina. */
/* Saman mokon tappoexpa reduce disable, koska liian vahan areoita + halutaa mortteja.
	9.11.98 Onarion
  if(sh) {
    percent = 100;
    percent = (percent*100) / (100+query_kills(sh));
    if(query_kills(sh) > 100) {
      tell_object(this_object(), "You don't learn much new by killing the same monster.\n");
    } else if(query_kills(sh) > 60) {
      tell_object(this_object(), "You gain less exp because killing the same monster.\n");
    }
    if(e > 1000000) {
      e = (e/100)*percent;
    } else {
      e = e*percent / 100;
    }
  */
  /* level 24 monsut ~ level 60-80 morttien soolotuskamaa */
  lvl_tmp = query_level();
  if(lvl_tmp > 80) lvl_tmp = 80;
  exp_tune = lvl_tmp - (leba + 5)*3/2;
  if(leba && exp_tune > 0) {
    if(exp_tune > 50) exp_tune = 50;
    if(e > 10000000)
      e -= e/100*exp_tune;
    else
      e -= e*exp_tune/100;
  }
  /* normaali exprate */
  if(e < 10000000)
    e = e*exp_rate/100;
  else
    e = e/100*exp_rate;

  if(sizeof(users()) >= 20 && sh) {
    tell_object(this_object(), "You gain a 10% bonus to the experience due high amount of players online.\n");
    if(e < 10000000)
      e = e*11/10;
    else
      e = e/10*11;
  }
  if(e > exp_gag_limit) tell_object(this_object(), "You receive "+e+" experience points.\n");
  add_skill_exps(e);
  exp_summary += e;
  if(e > 0 && !non_tune_xp)
    XP_TUNE_D->add_race_xp(query_race(), e);
}


add_intoxination(i) {
    if(i < 0)
    {
	if (-i > intoxicated / 10)
		i = -intoxicated / 10;
    }
    intoxicated += i;
    if(intoxicated < 0)
	intoxicated = 0;
}

add_stuffed(i) {
    if(i < 0) {
	if (-i > stuffed / 10)
		i = -stuffed / 10;
    }
    stuffed += i;
    if (stuffed < 0)
	stuffed = 0;
}

query_exp_summary() {
  return exp_summary;
}
query_money_summary() {
  return money_summary/100;
}
add_money_summary(int i) {
  money_summary += i;
}

add_soaked(i) {
    if(i < 0)
    {
	if (-i > soaked / 10)
		i = -soaked / 10;
    }
    soaked += i;
    if (soaked < 0)
	soaked = 0;
}

query_intoxination() {
    return intoxicated;
}

query_stuffed()
{
    return stuffed;
}

query_soaked()
{
    return soaked;
}

/* 3000 */


second_life() {
    object death_mark;
    if (Wiza > 0)
	return illegal_patch("second_life");

    if (tester) { tell_object(this_object(), "Second_life\n"); }
    ghost = 1;
    msgin = "drifts around";
    msgout = "blows";
    headache = 0;
    intoxicated = 0;
    stuffed = 0;
    soaked = 0;
    hunter = 0;
    hunted = 0;
    uncon = 0;
    sleep = 0;
    tell_object(myself, "\n\nYou die.\n\nYou have a strange feeling.\n" +
		"You can see your own dead body from above.\n\n");

    if (guest) { destruct(this_object()); return 0; }
    move_object(myself, "/world/special/hell");

    /* death bug was below this line //Celtron */
    death_log(attacker_ob);
    attacker_ob = 0;
    alt_attacker_ob = 0;

    if(ghost) call_other("/world/monsters/cleric", "offer_ress", myself);
    return 1;
}

set_dead(int arg) { dead = arg; }

int query_max_death_legacy_time() {
  return DEATH_LEGACY_TIME;
}

int query_death_legacy_time() {
  return death_legacy_time;
}

int remove_death_legacy() {
	death_legacy_time = 0;
	STAT_D->update_points(this_object());
	return 1;
}

remove_ghost(int save, mixed envi) {
    int i;
    if (!ghost)
	return 0;
    tell_object(this_object(), "You feel a very strong force.\n");
    tell_object(this_object(), "You are sucked away...\n");
    tell_object(this_object(), "You reappear in a more solid form.\n");
    say(cap_name + " appears in a solid form.\n");
    ghost = 0;
    dead = 0;
    if(save != 100) death_legacy_time = DEATH_LEGACY_TIME;
    
    while (i < 10) {
        if (save && sizeof(skill_exps) > i) {
	   skill_exps[i] = skill_exps[i] / 100 * save;
	} else {
    	   skill_train[i] = 0;
	   skill_exps[i] = 0;
	   skill_costs[i] = 0;
	   skill_left[i] = 0;
        }
	i += 1;
    }
    if (save) {
        tell_object(this_object(), "Experience summary reseted.\n");
        exp_summary = 0;
	level_exp = level_exp / 100 * save;
    } else {
        level_exp = 0;
    }
    msgin = "arrives";
    msgout = "leaves";

    make_scar();
    if(envi && stringp(envi) || envi && objectp(envi))
      move_object(this_object(), envi);
    else
      move_object(this_object(), "/world/city/inn");

    save_me(1);
    return 1;
}

death_log() {
  string msg;
  object ob;
  if(!attacker_ob) return 0;
  msg = ctime(time())+" "+cap_name+" ("+query_level()+") "+
	" was killed by "+attacker_ob->short()+" ("+attacker_ob->query_name()+") "+
	"("+attacker_ob->query_level()+") "+file_name(attacker_ob)+"\n";
  if(attacker_ob->query_tester()) {
    msg += attacker_ob->short()+" is a test char!\n";
  }

  if (attacker_ob->query_npc()) {
    log_file("KILLS",msg, 1);

  } else if(query_clan() && attacker_ob->query_clan() && query_clan() != attacker_ob->query_clan()) {
    clan_deaths += 1;
    reduce_total_worth(1000000);
    tell_object(attacker_ob, "You perform an accurate clan kill and cut "+query_real_name()+"'s head off.\n"); 
    tell_object(this_object(), "You feel drained as your defeat brings shame on your clan.\n");

    log_file("CLAN_KILLS", msg); 
    ob = clone_object("/clan/mutilated_head");
    ob->set_name(attacker_ob->query_real_name(), query_real_name());
    move_object(ob, attacker_ob);

    tell_object(this_object(), "You are revived due dying on a clankill.\n");
    remove_ghost(100);

  } else if(attacker_ob) {
    log_file("PLAYER_KILLS", msg);
  }

}

/*
else if(query_clan() && attacker_ob->query_clan() && query_clan() !=
	attacker_ob->query_clan()) {
    log_file("CLAN_KILLS", msg);
    CLAN_D->modify_clan_score(this_object(), attacker_ob);
    clan_deaths += 1;
    reduce_total_worth(100000);  100k kill minus 
    tell_object(attacker_ob, "You perform an accurate clan kill.\n");
    tell_object(this_object(), "You feel drained as your clan suffers a bitter defeat.\n");
  }
*/


query_train_exp(int save)
{
 int i, sum;
 sum=0;

 if(save)
 for (i=0;i<10;i++) 
	{
	 sum += skill_exps[i];
    	}

 sum += level_exp;

 if(sum<0) sum = 0;

 return sum;
}

query_hunter_list(object ob, arg) {
  int i;
  if (arg) { return hunter_list; }
  if(!ob) return;
  if(!hunter_list) {
        hunter_list = allocate(20);
  }
  while(i<sizeof(hunter_list)) {
    if(ob==hunter_list[i]) {
        return 1;
    }
    i+=1;
  }
}

add_hunter_list(object ob) {
  int i;
  if(!ob) return;
  if(!hunter_list) {
        hunter_list = allocate(20);
  }
  while(i<sizeof(hunter_list)) {
    if(hunter_list[i] == ob) { return; }
    if(!hunter_list[i]) {
        hunter_list[i] = ob;
        return 1;
    }
    i+=1;
  }
  hunter_list[random(20)] = ob;
  return 1;
}

remove_hunter_list(object ob) {
  int i;
  if (!hunter_list) { return; }
  if (!ob) { return; }
  while(i<sizeof(hunter_list)) {
    if(hunter_list[i] == ob) {
        hunter_list[i] = 0;
        return;
    }
    i+=1;
  }
}

reset_hunter_list() {
  hunter_list = 0;
  hunter = 0;
  hunted = 0;
  attacker_ob = 0;
}

drink_alcohol(i) {
}
drink_alco(i) {
}
drink_soft(i) {
  thirst += i;
  if(thirst > query_max_thirst()) {
    tell_object(this_object(), "You can't drink that much, you spit the rest out.\n");
    thirst = query_max_thirst();
  }
  return 1;
}
eat_food(i) {
  hunger += i;
  if(hunger > query_max_hunger()) {
    tell_object(this_object(), "You can't eat that much, you discard the rest of the food.\n");
    hunger = query_max_hunger();
  }
  return 1;
}
query_hunger() {
  return hunger;
}
query_thirst() {
  return thirst;
}
query_max_hunger() {
  return query_size() * 10000;
}
query_max_thirst() {
  return query_size() * 3000;
}

add_hunger(i) {
  if (Wiza) { return; }
  hunger -= random(i*query_size()/5);
}
add_thirst(i) {
  if (Wiza) { return; }
  thirst -= random(i*query_size()/5);
}
query_skill(str) {
  if(!str) return skill;
  return query_skills(str);
}

query_skills(mixed str) {
  int value;
  if(!str || !skills) {
    log_file("QUERY_SKILLS", ctime(time())+" "+query_name()+": "+file_name(previous_object())+" called with no arg.\n");
    return 0;
  }
  if (intp(str)) {
     write("Calling query_skills with number...aborted\n");
     return;
  }
  str = lower_case(str);
  value = skills[str];
// return here if no skill
  if(!value) return value;

/*
 * mapping learn_skill(string skill, mapping learn_map, object player, object prev_ob) {
 *
 * int skill_value(string skill, mapping learn_map, object player) {
 */
  if(!skill_learn) skill_learn = ([ ]);
  skill_learn = SKILL_LEARN_D->learn_skill(str, skill_learn, this_object(), previous_object());
  value += SKILL_LEARN_D->skill_value(str, skill_learn, this_object());

// rebirth +allskills bonus

  if(query_rebirth())
    value += REBIRTH_SKILLS_BONUS;

  // HC limit
  if(value >= 100) value = 100;
  return value;
}

query_level_exp() {
  return level_exp;
}

advance_skill(mixed num, int much) {
  string str;
  if(intp(num)) str = call_other(SKILLFUN,"skill_names",num);
  else str = num;
  str = lower_case(str);
  skills[str] = skills[str] + much;
  return 1;
}
set_skill(string num,much) {
    num = lower_case(num);
    skills[num] = much;
    if(much == 0) skills -= ([ num ]);
}

interrupt_spell() {
  if(spell) spell->interrupt_spell();
  if(skill) skill->interrupt_skill();
}

query_resists(string pref) {
  int res;
  res = resists[pref];
  if(pref == "fire" || pref == "cold")
    res += RACE_D->query_race_stat(query_race(), "resist");

// resist bonus for rebirth chars

  if(query_rebirth())
    res += REBIRTH_RESISTS_BONUS;

  return res;
}

move_interrupt_spell() {
    if (spell && !spell->query_resolving()) {
	write("Your concentration breaks as you move.\n");
	spell->interrupt_spell();
    }
    if (skill) {
	write("Your concentration breaks as you move.\n");
	skill->interrupt_skill();
    }
    return 1;
}

query_sp_boost(arg) {
  if (arg == 1) { return sp_boosts["offensive"]; }
}

set_sp_boost(arg,num) {
  sp_boosts[arg] = num;
}

static spell_zap(str) {
    object ob;
    if (!str)
	ob = attacker_ob;
    else
	ob = present(lower_case(str), environment(this_player()));
    if (!ob || !living(ob)) {
	write("At whom ?\n");
	return 1;
    }
    if(Wiza < 2 && !ob->is_npc()) { return; }
    if (!ob->query_npc()) {
    	log_file("ZAP_LOG", this_player()->query_name()+" zapped "+
		ob->query_name()+" ("+ctime(time())+")\n");
    }
    zap_object(ob);
    return 1;
}

static force_player(str) {
    string who, what;
    object ob;
    if (Wiza < 2) { return 0; }
    if (!str)
	return 0;
    if (sscanf(str, "%s to %s", who, what) == 2 ||
	sscanf(str, "%s %s", who, what) == 2) {
	ob = present(who);
	if(!ob) { ob = find_living(who); }
	if (!ob) {
	    write("No such player.\n");
	    return 1;
	}
	if (level <= ob->query_level() || Wiza <= ob->query_wiz()) {
	  write("Too low level.\n");
	  return 1;
	}
	command(what, ob);
	write("You force " + who + " to " + what + ".\n");
	return 1;
    }
    return 0;
}


static get_present_objects() {
  object ob;
  int i;
  write("Started search..\n");
  ob = all_inventory(environment(this_object()));
  while(i < sizeof(ob)) {
    write("% "+(i+1)+": "+ob[i]->query_name()+": "+ob[i]->short()+"\n");
    i += 1;
  }
  write("Returned.\n");
  return 1;
}

static destruct_local_object(str) {
    object ob;
    if (!str) {
	write("Destruct what ?\n");
	return 1;
    }
    str = lower_case(str);
    ob = present(str, this_player());
    if (!ob)
	ob = present(str, environment(this_player()));
    if (!ob && Wiza > 2) {
      ob = find_player(str);
    }
    if(!ob && Wiza > 2 && str == "all") {
      int i;
      ob = all_inventory(environment(this_object()));
      while(i < sizeof(ob)) {
	if(ob[i] != this_object()) {
	  destruct(ob[i]);
	}
	i += 1;
      }
      write("Done..\n");
      return 1;
    }
    if(!ob) {
      write("No " + str + " here.\n");
      return 1;
    }
    if (living(ob) && !ob->query_npc() && Wiza < 2) {
      write("You cannot destruct players.\n");
      return 1;
    }
    say(call_other(ob, "short") + " is disintegrated by " + cap_name + ".\n", ob);
    tell_object(ob, "You have been destructed by a Wizard.\n");
    destruct(ob);
    write(str + " destroyed.\n");
    return 1;
}

static home() {
    move_player("X#wizards/" + name + "/workroom");
    return 1;
}

static wiz_score_list(arg) {
    if (arg)
	wizlist(arg);
    else
	wizlist();
    return 1;
}

static remove_file(str) {
    if (!str)
	return 0;
    if (rm(str)) {
	write(str + " deleted.\n");
    } else {
	write("Failed.\n");
    }
    return 1;
}

static local_commands() {
    localcmd();
    return 1;
}

/*
 * Recursively compute the values of the inventory.
 * Beware that object may selfdestruct when asked for query_value().
 */
compute_values(ob) {
    int v;
    while(ob) {
	int tmp;
	object next_ob;

	next_ob = next_inventory(ob);
	tmp = ob->query_value();
	if (tmp > 1000)
	    tmp = 1000;
	v += tmp;
	if (ob && first_inventory(ob))
	    v += compute_values(first_inventory(ob));
	ob = next_ob;
    }
    return v;
}

query_no_savemode() {
  return !SAVEMODE;
}

save_me(value_items) {
    if (level < 2 && age < 3600 || guest) { return 1; }
    if(!SAVEMODE) return 0;
    compute_auto_str();
    if (value_items) {
        compute_recovery_str();
        safe_load = "";
    }
    else {
	recovery_load = "";
    }
    save_object("players/" + name);
    return 1;
}


illegal_patch(what) {
    write("You are struck by a mental bolt from the interior of the game.\n");
    log_file("ILLEGAL", ctime(time()) + ":\n");
    log_file("ILLEGAL",
	     call_other(this_player(), "query_real_name") + " " +
	     what + "\n");
    return 0;
}

load_auto_obj(str) {
    string file, argument, rest;
    object ob;

    while(str && str != "") {
	if (sscanf(str, "%s:%s^!%s", file, argument, rest) != 3) {
	    write("Auto load string corrupt.\n");
	    return;
	}
	str = rest;
	if(file) {
          if(ob = clone_object(file)) {
          } else {
	    log_file("BUG_EQ", ctime(time())+" "+file+"\n");
	    write("Error in loading eq.\n");
          }
        }
	if (argument && ob)
	    call_other(ob, "init_arg", argument);
	if (ob) move_object(ob, this_object());
    }
}

compute_auto_str() {
    object ob;
    string str;

    auto_load = "";
    ob = first_inventory(this_object());
    while(ob) {
	str = call_other(ob, "query_auto_load");
	ob = next_inventory(ob);
	if (!str)
	    continue;
	auto_load = auto_load + str + "^!";
    }
}

load_safe_obj(str) {
    string file, argument, rest;
    object ob;
    while(str && str != "") {
        if (sscanf(str, "%s^!%s", file, rest) != 2) {
            write("Safe load string corrupt.\n");
            return;
        }
        str = rest;
	sscanf(file, "%s#%s", file, argument);
	if(file) file = "/"+file+".c";
        if (file && file_size(file) != -1) {
	    if(ob = clone_object(file)) { }
	}
        if (ob) move_object(ob, this_object());
    }
    safe_load = "";
}

compute_safe_str() {
    object ob, next_ob;
    string str;
    /* jos safe_quit on bugannu ja ukko ei ole quitannut mutta ekut on jo safe_loadissa */
    if(safe_load != "")
      load_safe_obj(safe_load);
    safe_load = "";
    ob = first_inventory(this_object());
    while(ob) {
        str = file_name(ob);
        if (!str || !ob->short() || ob->query_auto_load()) {
	    ob = next_inventory(ob);
            continue;
  	}
 	if (!ob->query_no_save() || ob->query_weapon()) {
           safe_load = safe_load + str + "^!";
	}
	next_ob = next_inventory(ob);
	destruct(ob);
	ob = next_ob;
    }
  return safe_load;
}

load_recovery_obj(str) {
    string file, argument, rest;
    object ob;
    if (str && str != "") { write("CRASH RECOVERY.\n"); }
    while(str && str != "") {
        if (sscanf(str, "%s^!%s", file, rest) != 2) {
            write("Recovery string corrupt.\n");
            return;
        }
        str = rest;
	sscanf(file, "%s#%s", file, argument);
	if(file) file = "/"+file+".c";
        if(file && file_size(file) != -1) ob = clone_object(file);
        if(ob) move_object(ob, this_object());
    }
    fix_weight();
}

compute_recovery_str() {
    object ob;
    string str;

    recovery_load = "";
    ob = first_inventory(this_object());
    while(ob) {
        str = file_name(ob);
        if (!str || !ob->short() || ob->query_auto_load()) {
	    ob = next_inventory(ob);
            continue;
  	}
 	if (!ob->query_no_save("recovery")) {
            recovery_load = recovery_load + str + "^!";
	}
	ob = next_inventory(ob);
    }
}

smart_report(str) {
    string who;
    string current_room;

    current_room = file_name(environment(this_object()));
    if (sscanf(current_room, "/wizards/%s/", who) != 1)
	return;
    log_file(who + ".rep", current_room + " " + str + "\n");
}

reset_quests() {
  if(this_player()->query_wiz() < 3) return 0;
  quests = 0;
  reinc_quests = 0;
  quest_points = 0;
  max_quest_points = 0;
}

/* func meant to set the amount of qb's straight without conversion&var reset //Celtron */
//Fixed by Rag, the old function gave wrong amount of QP's
fix_quest_points() {
  string *rest;
  int i,p;
  p = 0;
  if(!quests) {
  	return 1;
  }
  rest = explode(quests,"#");
  for(i = 0;i<sizeof(rest);i++) {
  	p += (int)QUEST_D->validate_quest(rest[i]);
  }
  if(quest_points > p)
      quest_points = p;
  max_quest_points = p;
  return 1;
}

query_quests(mixed str) {
    string tmp, rest, rest_tmp;
    int i;

    if (str == 0)
	return quests;
    if (str == -1)
	return reinc_quests;

    rest = quests;
    while(rest) {
	if (str == rest)
	    return 1;
	i = sscanf(rest, "%s#%s", tmp, rest_tmp);
	if (i == 0) 
	    break;
	if (tmp == str)
	    return 1;
	if (i == 1)
	    break;
	rest = rest_tmp;
    }
    rest = reinc_quests;
    while(rest) {
	if (str == rest)
	    return 1;
	i = sscanf(rest, "%s#%s", tmp, rest_tmp);
	if (i == 0)
	    return 0;
	if (tmp == str)
	    return 1;
	if (i == 1)
	    return 0;
	rest = rest_tmp;
    }
    return 0;
}

/* if !r quest is reinc_proof. should be r == 0 */
set_quest(string q, int r) {
  int p;
  if (!q) return 0;
  if (query_quests(q)) return 0;
  /* see if quest is valid and approved */
  p = (int)QUEST_D->validate_quest(q);
  if(!p) {
    log_file("INVALID_QUESTS", ctime(time())+", "+query_name()+" "+file_name(previous_object())+" quest: "+q+"\n");
    return 0;
  } 
  if (previous_object()) {
    log_file("QUESTS", ctime(time())[4..9]+ ", "+ name + ": " + q + " FILE: " +
		 file_name(previous_object()) + " AWARD: "+p+"\n");
    if (this_player() && this_player() != this_object() &&
	  query_ip_number(this_player()))
      log_file("QUESTS", "Done by " +
		     this_player()->query_real_name() + "\n");
  }

  /* if quest is cleared in reinc, questpoints cannot be given (cheat possibility) */
  if (r) {
    if (!reinc_quests)
      reinc_quests = q;
    else
      reinc_quests = reinc_quests + "#" + q;
    return 1;
  }

  if (p) tell_object(this_object(), "You receive "+p+" quest points.\n");
  quest_points += p;
  max_quest_points += p;

  if (!quests) quests = q;
  else quests = quests + "#" + q;
  return 1;
}

query_quest_points() {
  return quest_points;
}

add_quest_points(int i) {
  if(this_player()->query_wiz() < 4) return -1;
  quest_points += i;
  max_quest_points += i;
}

query_max_quest_points() {
   return max_quest_points;
}

reduce_quest_points(i) {
   quest_points -= i;
}

reset_quest_points() { quest_points = max_quest_points; }

query_level_paid() {
   return level_paid;
}

set_level_paid(i) {
   level_paid = i;
}

query_real_name() {
    return name;
}

time_out() {
    write("Time out\n");
    destruct(this_object());
}

query_current_path() {
  return current_path;
}

set_path(string str) {
  current_path = str;
}

#define CHUNK 16

static string more_file;        /* Used by the more command */
static int more_line;

more(string str) {
    if (!str)
	return 0;
    more_file = (string)SIMUL->valid_read(str, this_object());
    if (!more_file) {
	write("Sorry, read access denied.\n"); 
	return 1; 
    }
    if (more_file == "-1") {
   	write("Access denied.\n");
	return 1;
    }
    more_line = 1;
    if (cat(more_file, more_line, CHUNK) == 0) {
	more_file = "/" + current_path + "/" + str;
   	if (cat(more_file, more_line, CHUNK) == 0) {
	    write("No such file\n");
	    return 1;
	}
    }
    input_to("even_more");
    write("More: (line " + (CHUNK + 1) + ") ");
    return 1;
}

static even_more(str) {
    if (str == "" || str == "d")
	more_line += CHUNK;
    else if (str == "q") {
	write("Ok.\n");
	return;
    } else if (str == "u") {
	more_line -= CHUNK;
	if (more_line < 1)
	    more_line = 1;
    }
    if (cat(more_file, more_line, CHUNK) == 0) {
	more_file = 0;
	write("EOF\n");
	return;
    }
    write("More: (line " + (more_line + CHUNK) + ") ");
    input_to("even_more");
}

pwd() {
    write("/" + current_path + "\n");
    return 1;
}

makedir(str) {
    if (!str)
	return 0;
    if (mkdir(str))
	write("Ok.\n");
    else
	write("Fail.\n");
    return 1;
}

removedir(str) {
    if (!str)
	return 0;
    if (rmdir(str))
	write("Ok.\n");
    else
	write("Fail.\n");
    return 1;
}

query_path() {
    return current_path;
}

query_scar() { 
    return scar; 
}

remove_scar() {
    int old_scar, first;
    old_scar = scar;
    if (number_of_scars < 1) { return; }
    first = 1;
    while (scar > old_scar || first == 1) {
	first = 0;
	scar = old_scar ^ 1 << random(MAX_SCAR);
    }
    if (number_of_scars) {
        number_of_scars -= 1;
	this_object()->update_stats();
    }
    return 1;
}

make_scar() {
    if (level <= 10)
	return;
    scar |= 1 << random(MAX_SCAR); /* rnd scarin slottiin pistetaan marker */
    if (number_of_scars < MAX_SCAR) {
        number_of_scars += 1;
	this_object()->update_stats();
    }
}

show_scar() {
    int i, j, first, old_value;
    string scar_desc;

    scar_desc = ({ "left leg", "right leg", "nose", "left arm", "right arm",
		   "left hand", "right hand", "forhead", "left cheek",
		   "right cheek", "neck" });
    j = 1;
    first = 1;
    old_value = scar;
    while(i < MAX_SCAR) {
	if (scar & j) {        /* jos scarin bit slotissa j on jotain */
	    old_value &= ~j;   /* old valuen j slotti pois */
	    if (first) {
		write(cap_name + " has a scar on " + query_possessive() +
		      " " + scar_desc[i]);
		first = 0;
	    } else if (old_value) {  /* kun old_value ei viela ole tyhja */
		write(", " + query_possessive() + " " + scar_desc[i]);
	    } else {
		write(" and " + query_possessive() + " " + scar_desc[i]);
	    }
	}
	j *= 2; /* vaihdetaan bittislottia */
	i += 1;
    }
    if (!first)
	write(".\n");
}

void set_email(string str) {
  if(this_player() != this_object()) return;
  mailaddr = str;
}
string query_email() { return mailaddr; }

/* 4000 */

exp(string str) {
    object ob;
    if (Wiza && str) {
       ob = find_player(str);
    }
    if (!ob) { ob = this_object(); }
    if (str == "clear") {
	remove_skill_train();
    	write("Training removed.\n");
	if (level_exp < level_cost / 2) {
	   write("Level advance removed.\n");
	   clear_level_advance();
	} else if (level_cost) {
	  write("Cannot remove level advance, you have more than half "+
		"of the required amount.\n");
	}
	return 1;
    }
    if(str && sscanf(str,"clear %s",str) == 1) {
      remove_skill_train(str);
      return 1;
    }
    if(str && sscanf(str,"limit %d",str) == 1) {
      exp_gag_limit = str;
      write("You will only be notified if you receive more than "+str+" experience points.\n");
      return 1;
    }
    ob->exps();
    return 1;    
}

sc(str) {
    if (str == "on") {
	write("Change in SC status is now automatically displayed.\n");
	sc_on = 1;
	return 1;
    }
    if (str == "off") {
	write("Change in SC status is now not automatically displayed.\n");
	sc_on = 0;
	return 1;
    }
    if (!check_condis()) { return 1; }
    write("Hp: "+hit_point + "(" + query_max_hp() + ") Sp: " + spell_points +
         "(" + max_sp+") Ep: " + endurance_points + "(" + max_ep + ")\n");
    return 1;
}

restore_player(string nam) {
    string str,tmp1,tmp2;
    str = "players/" + nam;
    if (sscanf(str, "%s..%s",tmp1,tmp2)) { return 0; }
    if(interactive(this_object()) && query_name() != "Logon") {
	log_file("ILLEGAL_RESTORE_PLAYER", ctime(time())+" "+this_player()->query_name()+" "+file_name(previous_object())+"\n");
	return 1;
    }
    if (restore_object(str)) {
	name = nam;        
	cap_name = nam;         
	return 1;
    }
    else if (restore_object("converse/"+nam)) {
	write("Unconversed character.\n");
	name = nam;
	cap_name = nam;
	return 1;
    }
    return 0;
}

query_keep(object ob) {
  return keep[ob];
}

query_last_ip() { return called_from_ip; }

show_idle(str) {
    object ob;
    if(!str) {
	write("Usage: idle <player>\n");
	return 1;
    }
    ob = find_player(lower_case(str));
    if (ob && !ob->query_link_dead() && !ob->query_invisible()) 
    {
     write(capitalize(str) + " has been idle for " + stime(ob->idle())+".\n");
    } else {
	    write("No such a player.\n");
           }
    return 1;
}


idle() {
  if (!interactive(this_object())) { return 30; }
  return query_idle(this_object());
}

query_plan() {
  return plan;
}

query_enter_time() {
    if (query_link_dead()) {
	return time_ld;
    }
    return enter_time;
}

// newpartyfuntions 
void set_party(object ob) { party_object = ob; }
object query_party() { return party_object; }

modify_command(string komento) {
  int i;
  string new_cmd;
  if (away) {
	write("You are no longer away.\n");
	away = 0;
  }
  if(sscanf(komento, "& %s", komento) == 1) {
    return komento;
  }
  if (this_interactive()) {
    if(this_interactive()->query_name() != this_object()->query_name() ||
       this_player()->query_name() != this_object()->query_name()) {
      return komento;
    }
  }
  if(komento == "%") { command(last_command, this_object()); return 1; }
  last_command = komento;
  if(komento && strlen(komento) > 5) add_history(komento);
  if(sscanf(komento, "%d %s", i, komento) == 2) {
    if(i<1||i>10) { return 0; }
    new_cmd = auto_shortcuts(komento);
    if (new_cmd) {
      komento = new_cmd;
    }
    while(i>=2) {
      command("& "+komento, this_object());
      i -= 1;
    }
    return komento;
  }

  new_cmd = auto_shortcuts(komento);
  if (new_cmd) {
    komento = new_cmd;
  }
  new_cmd = COMMAND_D->query_command(komento);
  if (new_cmd) {
    komento = new_cmd;
  }
  if(COMMAND_D->ansicheck(komento) && !this_player()->query_tester()) {
    tell_object(this_object(), "Ansi code detected. Command aborted.\n");
    return "";
  }
  return komento;
}

auto_shortcuts(str) {
  int slot;
  string cmd,arg,msg;
  if (str == "uncommand") {
    tell_object(this_object(), "All commands cleared.\n");
    command = allocate(sizeof(command));
    return "";
  }

  if (str == "n") { return "north"; }
  if (str == "s") { return "south"; }
  if (str == "e") { return "east"; }
  if (str == "w") { return "west"; }
  if (str == "nw") { return "northwest"; }
  if (str == "ne") { return "northeast"; }
  if (str == "sw") { return "southwest"; }
  if (str == "se") { return "southeast"; }
  if (str == "u") { return "up"; }
  if (str == "d") { return "down"; }
  if (sscanf(str, "on %s", str)) { return "channels join "+str; }
  if (sscanf(str, "off %s", str)) { return "channels leave "+str; }
  if (sscanf(str, "%s %s", cmd, arg) != 2) { cmd = str; }

  while(slot < AMOUNT_OF_COMMANDS) {
    if (command[slot] == cmd) {
      if (!arg) { return command[slot+1]; }
      return command[slot+1] + " " + arg;
    }
    slot += 2;
  }
}

show_history() {
  int i;
  i = sizeof(history)-1;
  while(i>=0) {
    if (history[i]) {
      write("% " +i+": "+history[i]+"\n");
    }
    i -= 1;
  }
  return 1;
}

query_history() {
return history;
}

set_command(str,blah,jees) {
    int slot, i;
    string keyword,action;
  if(sizeof(command) < AMOUNT_OF_COMMANDS) {
    command = allocate(AMOUNT_OF_COMMANDS);
    write("Resizing command array....done\n");
    return 1;
  }

  if(jees) return 1; /* case enter */

    if (!str) {
        write("Current commands:\n");
        while(slot < AMOUNT_OF_COMMANDS-2) {
	  if (command[slot]) { write(command[slot]+" -> "+ command[slot+1]+"\n"); }
	  slot += 2;  
        }
        return 1;
    }	
    while(command[slot] && slot < AMOUNT_OF_COMMANDS-2) {
        slot += 2;
    }
    if (!command[slot] || sscanf(str, "%s %s", keyword, action) != 2) {
        if (sscanf(str, "%s %s", keyword, action) == 2) {
	  if (keyword && keyword != "") {
	    set_command(keyword,1);
	    command[slot] = keyword;
	    command[slot+1] = action;
	    write("Command '"+ keyword +"' -> '"+ action+"' added.\n");
	    return 1;
	  }
	}
	keyword = str;
	slot = 0;
	while(slot < AMOUNT_OF_COMMANDS-2) {
	  if (keyword == command[slot]) {
	    write("Removed command " + keyword + ".\n");
	    command[slot] = 0; command[slot+1] = 0;
	    return 1;
	  }
	  slot += 2;
	}
	if(!blah) { write("Usage: command <keyword> <action>\n"); }
	return 1;
    }
    write("Too many commands already. Replace/remove old ones.\n");
    return 1;
}
static add_history(arg) {
    int i;
    i = sizeof(history)-1;
    while(i>0) {
        history[i] = history[i-1];
        i -= 1;
    }
    history[0] = arg;
}
static repeat(cmd,num) {
  int i;
  while(i<num) {
    command(cmd, this_object());
    i += 1;
  }
  return 1;
}

reboot_time() {
  object ob;
  ob = find_object("/obj/timer");
  write("The end of world is here in "+ob->query_time_to_boot()+"\n");
  return 1;
}

show_date() {
  write("QuestMud local time (Eastern European Time [EET]):\n"+ctime(time())+"\n");
  return 1;
}
change_terminal(str) {
  if(str == "ansi") {
    terminal = 1;
    write("Terminal ansi..\n");
    return 1;
  }
  if(str=="network") {
    terminal = 0;
    write("Terminal network..\n");
    return 1;
  }
  write("Usage: terminal [ansi|network]\n");
  return 1;
}

query_terminal() {
  return terminal;
}

player_set(string str) {
  string tmp;
  if(str && sscanf(str, "%s %s", tmp, str) == 2 && tmp == "counter") {
    if(str == "none")
      write("You stop countering spells.\n");
    else if(str == "all") 
      write("You will try to counter all spells you see.\n");
    else
      write("You will try to counter "+capitalize(str)+"'s spells and all of those cast on you.\n");
    counter_target = str;
    return 1;
  }
  if (str == "elusive") {
    if (!elusive) {
      elusive = 1;
      write("You are now trying to hide your spellcasting.\n");
      return 1;
    } else {
      elusive = 0;
      write("You are no longer trying to hide your spellcasting.\n");
      return 1;
    }
  }
  write("Usage: set counter [all | none | <target>]\n      set elusive\n");
  return 1;
}

query_counter() { 
  return counter_target;
}

query_elusive() { return elusive; }

/* reinc resets almost everything */
reinc(int cost_percent) {
    int i;
    unshadow();
    if(cost_percent) {
      tell_object(this_object(), "Due to reincarnation, you lose "+cost_percent+"% of your total experience.\n");
      totals = reduce_by_percent(totals, cost_percent);
    }
    add_worth_to_free_exp();
    totals = "0";
    while (i < 10) {
        if (skill_train[i]) {
             add_free_exp(skill_exps[i]);
        }
        i += 1;
    }
    add_free_exp(level_exp);
    if (!Wiza)
       level = 0;

    starter_guild = 0;
    level_exp = 0;
    experience = 0;
    level_cost = 0;
    level_guild = 0;
    clan_deaths = 0;
    skills =([ ]);
    skill_learn = ([ ]);
    guild_levels = ([ ]);
    stat_max = ([ ]);
    stat_trait = ([ ]);
    traits = ([ ]);
    stat_percent = ([ ]);
    sp_boosts = ([ ]);
    sp_boosts["offensive"] = 40;
    skill_train = allocate(10);
    skill_left = allocate(10);
    skill_costs = allocate(10);
    skill_exps = allocate(10);
    best_solo = 0;
    best_party = 0;
    best_solo_exp = 0;
    best_party_exp = 0;
    scar = 0;
    number_of_scars = 0;
    reinc_quests = 0;
    alignment = 0;
    reset_quest_points();
    reset_wishes();
    last_reinc_time = time();
    GUILDRANK_D->reset_guild_leader(0, lower_case(query_real_name()));
    /* there are many converse levels */
    if(conversed < 9) {
      write("You have old quests. Clearing questdata..\n");
      reinc_quests = 0;
      quests = 0;
      quest_points = 0;
       max_quest_points = 0;
    }
    if(conversed < 10) {
      write("Conversing exp..\n");
      /* if old exp is bigger */
      if("/daemons/explist"->higher("/daemons/exp_restore"->query_old_totals(query_name()), query_total_string()) &&
	"/daemons/exp_restore"->query_old_totals(query_name()) != -1) {
        reset_totals();
        reset_free_exp();
        free_exp = "/daemons/exp_restore"->query_old_totals(query_name());
      }
    }
    /* mark the converse done */
    if(CONVERSE != conversed) conversed = CONVERSE;
    mastery = ([ ]);
    return 1;
}

clear_best_kills() {
  if(this_player()->query_wiz()<3) return;
  best_solo = 0;
  best_party = 0;
  best_solo_exp = 0;
  best_party_exp = 0;
}

query_conversed() {
  return conversed;
}

set_best_kill(str,num,member_num) {
    if (tester) { write("Set_best_kill called.\n"); }
    if (!member_num) {
	if (best_solo_exp < num) {
	    best_solo_exp = num;
	    best_solo = str;
	}
    } else {
    	if (best_party_exp < num) {
	    best_party_exp = num;
	    best_party = str;
	    best_party_number = 0;
	}
    }
}

query_best_kills() {
    if (!best_solo && !best_party) { return 1; }
    if (!best_solo && best_party_number) {
  	write("Best kill: " + best_party + ": " + best_party_exp + " exp (party of "+best_party_number+")\n");
	return 1;
    } else if (!best_solo) {
  	write("Best kill: " + best_party + ": " + best_party_exp + " exp (party)\n");
	return 1;
    }
    if (!best_party) {
  	write("Best kill: " + best_solo + ": " + best_solo_exp + " exp (solo)\n"); 
	return 1;
    }
    write("Best kills: " + best_solo + ": " + best_solo_exp + " exp (solo)\n"); 
    if (best_party_number) {
      write("            " + best_party + ": " + best_party_exp + " exp (party of "+best_party_number+")\n");
    } else {
      write("            " + best_party + ": " + best_party_exp + " exp (party)\n");
    }
    return 1;
}

status cmd_handler(string str) {
 string cmd,command,file,tmp,tmp2,rdystr;
string *freestr;
int i;
 cmd = query_verb();
/*
if(this_player()->query_wiz() == 4) write("DEBUG: "+str+"\n");
*/

 if(sscanf(cmd, ".%s", tmp) == 1 ||
   sscanf(cmd, "%s.%s", tmp, tmp2) == 2 && !query_wiz()) return 0;
 command = "cmd_"+cmd;

/*
  if(str && this_player()->query_real_name() == "garathius") {
    freestr = explode(str," ");
    for(i=0;i<sizeof(freestr);i++) {
       if(aliases != 0) {
         if(aliases[freestr[i]]) {
           str += aliases[freestr[i]];
         } else {
           str += freestr[i];
         }
       }
    }
  }

*/
 if(Wiza) {
   file = "/cmds/wiz/" + "_" + cmd + ".c";
   if(file_size(file) != -1)
     return call_other(file, command, str);
 }
 if(Wiza >= 3) {
   file = "/cmds/adm/" + "_" + cmd + ".c";
   if(file_size(file) > 0)
     return (int)call_other(file, command, str);
 }
 file = "/cmds/std/_" + cmd + ".c";
 if(file_size(file) > 0)
   return (int)call_other(file, command, str);

  return EMOTE_D->process_cmd(str);

}

away(str) {
    if (!str) {
	write("Give message as an argument.\n");
	return 1;
    }
    write("You are now away.\n");
    away = str;
    return 1;
}

query_away() { return away; }

int channels(string arg) {
  string channcomm, argument,channame,arg2;
  string nimi, chanu;
  if(query_guest()) {
    write("Guests have no channel access.\n");
    return 1;
  }
  if(!arg) {
    CHANNEL_D->channel_list();
    return 1;
  }
  if(sscanf(arg,"%s %s",channcomm,argument)==1) {
    channcomm=arg;
  }
  if(channcomm=="create") {
    if(!argument) {
      write("You must give name to the channel that you want create.\n");
      return 1;
    }
    CHANNEL_D->add_channel(argument);
    return 1;
  }
  if(channcomm=="topic") {
    if(!argument) {
      write("You must give an argument to this command.\n");
      return 1;
    }
    if(sscanf(argument,"%s %s",channame,arg2)!=2) {
      channame=argument;
    }
    CHANNEL_D->change_topic(channame,arg2);
    return 1;
  }
  if(channcomm=="join") {
    if(!argument) {
      write("That channel command demands an argument.\n");
      return 1;
    }
    if(CHANNEL_D->channel_exists(argument)==0) {
      write("No such channel.\n");
      return 1;
    }
    if(CHANNEL_D->valid_join(argument)==0) {
      write("No such channel.\n");
      return 1;
    }
    if(this_object()->add_channel(argument))
      write("You join channel "+argument+".\n");
    else
      write("Failed to join. ("+argument+")\n");
    return 1;
  }
  if(channcomm=="who") {
    if(!argument) {
      write("This channel command requires an argument.\n");
      return 1;
    }
    if(CHANNEL_D->write_channel_who(argument)) return 1;
    else {
      write("No such channel.\n");
      return 1;
    }
  }
  if(channcomm=="send") {
    if(!argument) {
      write("That channel command demands an argument.\n");
      return 1;
    }
    if(sscanf(argument,"%s %s",channame,arg2)!=2) {
      write("Say what on channel?\n");
      return 1;
    }
    if(channame=="inform") return 0;
    if(sizeof(lochannels)==0) {
      write("You are not on such channel.\n");
      return 1;
    }
    if(member_array(channame,lochannels)==-1) {
      write("You are not on such channel.\n");
      return 1;
    }
    CHANNEL_D->send_to_channel(channame,arg2);
    return 1;
  }
  if(channcomm=="leave") {
    if(this_object()->remove_channel(argument)) {
      write("You left the channel.\n");
      return 1;
    }
    else {
      write("You are not on such channel.\n");
      return 1;
    }
  }
  write("No such channel command yet implemented.\n");
  return 1;
}

remove_chan_delay() {
  chan_delay = 0;
}

int add_channel(string chan) {
  if(chan == "channels") return 0;
  if(sizeof(lochannels)>0) {
    if(member_array(chan,lochannels)==-1) {
      lochannels=lochannels+({ chan });
      add_action("channel_parser",chan);
      return 1;
    }
  }
  else {
    lochannels=({ chan });
    add_action("channel_parser", chan);
    return 1;
  }
  return 0;
}

int remove_channel(string chan) {
  if(sizeof(lochannels)>0) {
    if(member_array(chan,lochannels)!=-1) {
      lochannels=lochannels-({ chan });
      return 1;
    }
  }
  return 0;
}

string *query_channel() { return lochannels; }

int channel_parser(string arg) {
  if(sizeof(lochannels)==0) return 0;
  if(member_array(query_verb(),lochannels)==-1) return 0;

  if(!arg) {
    this_object()->channels("who "+query_verb());
    return 1;
  }
  if(query_verb()=="inform" && arg == "last") {
    CHANNEL_D -> send_to_channel(query_verb(), arg);
    return 1;
  }
  if(query_verb()=="inform" && this_player()->query_wiz() < 3) return 0;

  if(chan_delay >= 10) {
    write("Spam limit reached, wait a while.\n");
    return 1;
  }
  if(query_wiz() < 3) {
    if (!chan_delay) { call_out("remove_chan_delay",10); }
    chan_delay += 1;
  }
  CHANNEL_D->send_to_channel(query_verb(),arg);
  return 1;

}

query_bbrief() { return bbrief; }

set_bbrief() {
  if(bbrief == 1) {
    write("Battle verbose on.\n");
    bbrief = 0;
  } else {
    write("Battle brief on.\n");
    bbrief = 1;
  }
  return 1;
}

keep(string str) {
  object item_o;
  int i, num;
  if(!str) {
    write("See 'help keep'\n");
    return 1;
  }
  if(str == "clear") {
    write("Keep list cleared.\n");
    keep = ([ ]);
    return 1;
  }
  item_o = present(str);
  if(keep[item_o]) {
    write("Removed "+item_o->short()+" from keep.\n");
    keep -= ([ item_o ]);
    return 1;
  }
  item_o = call_other("/daemons/filter", "EQ_FILTER", str, this_object());
  if (!item_o) {
    write("Nothing added to keep list.\n");
    return 1;
  }
  while (i < sizeof(item_o)) {
    if (item_o[i]->short() && !keep[item_o[i]]) {
      keep += ([ item_o[i] : 1 ]);
      num += 1;
    }
    i += 1;
  }
  write("Modified keep status for " +num+ " items.\n");
  return 1;
}

add_standard_commands() {
    int i;
    add_action("set_bbrief", "battle");
    add_action("change_terminal", "term");
    add_action("show_date", "date");
    add_action("show_date", "time");
    add_action("set_email", "email");
    add_action("save_character", "save");
    add_action("quit", "quit");
    add_action("kill", "kill");
    add_action("shout_to_all", "shout");
    add_action("look", "l");
    add_action("change_password", "password");
    add_action("idea", "idea");
    add_action("typo", "typo");
    add_action("bug", "bug");
    add_action("converse", "converse");
    add_action("toggle_brief", "brief");
    add_action("toggle_whimpy", "wimpy");
    add_action("exp", "exp");
    add_action("sc", "sc");
    add_action("show_idle", "idle");
    add_action("remove_ghost", "pray");
    add_action("fix_stats", "fix_stats");
    add_action("fix_ac", "fix_ac");
    add_action("fix_weight", "fix_weight");
    add_action("set_command", "command");
    add_action("show_history", "history");
    add_action("set_surname", "surname");
    add_action("modify_plan", "plan");
    add_action("rep", "rep");
    add_action("link_death", "ld");
    add_action("reboot_time", "reboot");
    add_action("bell", "bell");
    add_action("player_set", "set");
    add_action("channels", "channels");

    add_action("say_shortcut", "'", 1);

    add_action("cmd_handler", "", 1);
    add_action("away", "away");
    add_action("keep", "keep");

    if(sizeof(lochannels)>0) {
      for(i=0;i<sizeof(lochannels);i++) {
  	add_action("channel_parser",lochannels[i]);
      }
    }
}


int say_shortcut(string str) { // Nalle
string temp;
 if(!str) 
   {
    str="";
   }

 sscanf(query_verb(),"'%s",temp); // remove '

 if(strlen(str)) str=" "+str; // add the space after verb if applicable
 str=temp+str; // compose the string

 (object) ("/cmds/std/_say");
 "/cmds/std/_say"->cmd_say(str);
return 1;
}

mapping query_aliases() { return aliases; }
void set_alias(string pre,string aft) {
  if(!aliases) aliases = ([ ]);
  if(aliases[pre]) aliases[pre] = aft;
  else aliases += ([ pre:aft, ]);
}

/* 5000 */

