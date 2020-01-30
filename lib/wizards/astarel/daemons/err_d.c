// ExpRateReport-daemon v0.2a

/* VARS */
int new_summary, old_summary, temp_sum;
int rate, short_rate;
int short_time, party_short_time, temp_time;
int party_summary, party_old_summary;
int party_rate, party_short_rate;
int reduce_time;
status active_flag;
string exp_string;
string raw;

mapping data;

/* DEFINES */
#define NAME ob[i]->query_name()

#define EXP_STRING 	data[NAME,0]
#define OLD_SUM 	data[NAME,1]

#define RATE	   	data[NAME,2]
#define S_RATE		data[NAME,3]

#define SHORT_TIME	data[NAME,4]
#define SHORT_P_TIME 	data[NAME,5]

#define P_SUMMARY	data[NAME,6]
#define P_O_SUMMARY  	data[NAME,7]

#define P_RATE		data[NAME,8]
#define P_S_RATE	data[NAME,9]
#define ACTIVE		data[NAME,10]

#define SYCLE_TIME	600 // 10min interval
#define IDLE_LIMIT	300 // 5min idle-limit
#define PARTY		ob[i]->query_party()


/* PROTOS*/
status filter_mortals(object ob);
void reset_vars();
void create_daemon_mapping();
string get_exp_string(string str);

/* CODE */
void reset(status arg) {
	
	if(arg)return;
	reset_vars();
	create_daemon_mapping();
}



void create_daemon_mapping() {
	
	object *ob;
	int i;

	if(!mappingp(data)) data = ([ ]);
	reset_vars();

	
	ob = users();

	ob = filter_array(ob,"filter_mortals");

	// Lets start the (bi)-sycle
	
	for(i = 0; i < sizeof(ob); i++) {
	reset_vars();
		if(NAME == "Logon")continue;
		if(!data[NAME]) {
	
			data += ([NAME : exp_string; old_summary; rate; short_rate; short_time; party_short_time; party_summary; party_old_summary; party_rate; party_short_rate; active_flag, ]);
		}
		
		
	
	// Summary hasn't changed -> skip	
	
	if(OLD_SUM == (ob[i]->query_exp_summary()/1000)) {
		ACTIVE = 0;
		SHORT_TIME = (time() - ob[i]->query_enter_time()) /60;		
		continue;
	}
	
	// Our person is idling too much
		if(ob[i]->query_idle() >= IDLE_LIMIT) {
		SHORT_TIME = (time() - ob[i]->query_enter_time()) /60;
		ACTIVE = 0;
		continue;
	}
	
	// Our beloved mort is (link) dead	
		if(ob[i]->query_link_dead()) {
			SHORT_TIME = ob[i]->query_link_dead() /60;
		}

	new_summary = ob[i]->query_exp_summary() / 1000;
	
	old_summary = OLD_SUM;
	OLD_SUM = new_summary;
	
	temp_sum = new_summary;
	
	//Lets get the all-time-in-time-rate
	temp_time = time() - ob[i]->query_enter_time();
	temp_time /= 60;
	if(temp_time <= 0)temp_time = 1;
	
	RATE = new_summary / temp_time;
	
	// then lets get the short-time-rate
	//temp_time = time() - ob[i]->query_enter_time() - SYCLE_TIME;
	temp_sum -= (old_summary / 1000);
	
	if(temp_sum <= 0) temp_sum = 1;
	if(temp_time <= 0) temp_time = 1;
	
	
	temp_sum /= 10;
	S_RATE = temp_sum;
	
	// Its PARTY-TIME!
	if(ob[i]->query_party()) {
		
		if(P_SUMMARY >= 1)P_O_SUMMARY = P_SUMMARY;
		
		new_summary = PARTY->query_party_total_exp() / 1000;
		
		P_SUMMARY = new_summary;
		
		temp_time = (time() - PARTY->query_party_creation_time()) / 60;
		if(temp_time <= 0)temp_time = 1;
		
		// PARTY-big-time-rate
		P_RATE = P_SUMMARY / temp_time;
		
		// PARTY-not-so-big-rate
		
		temp_time = (time() - PARTY->query_party_creation_time() - SYCLE_TIME / 60) / 60;
		
		P_S_RATE = (P_SUMMARY - P_O_SUMMARY) / SYCLE_TIME;
		
		P_O_SUMMARY = PARTY->query_party_total();
				
	}
	OLD_SUM = ob[i]->query_exp_summary();
	EXP_STRING = "/wizards/astarel/cmds/mstats"->expat_sillai_hienosti(ob[i]);
	SHORT_TIME = (time() - ob[i]->query_enter_time()) / 60;	
	ACTIVE = 1;

	
	

}

}

void print_data() {
	
	int i;
	object *ob;
	string guild;
	string active;
	
			
	ob = users();
	
	ob = filter_array(ob,"filter_mortals");
	
	create_daemon_mapping();
	
	if(find_call_out("create_daemon_mapping") == -1)call_out("create_daemon_mapping", SYCLE_TIME);
	
	for(i=0;i<sizeof(ob);i++) {
	
		if(ob[i]->query_starter_guild()) guild = ob[i]->query_starter_guild()[0];
		else guild = "none";
		
		if(ACTIVE == 1)	active = "yes";
		else active = "no";
				
		write("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		write("Name: "+NAME+" Rate:"+RATE+"k/min   "+SYCLE_TIME/60+"min Rate: "+S_RATE+"k/min\n");
		if(PARTY) {
		write("P-rate: "+P_RATE+"k/min" +SYCLE_TIME/60+"min P-rate: "+P_S_RATE+"k/min\n");
		}
		write("Totals: "+EXP_STRING+" Todays summary: "+get_exp_string(to_string(ob[i]->query_exp_summary()))+"\n");
		write("Primary guild: "+guild+" Active: "+active);
	}
	
}

string get_exp_string(string str) {

	int i,a;
	string stemp,stemp2;


	stemp = str;

	if(strlen(stemp) <= 6) return "Below 1 Meg";
	stemp2 = "";
	a = strlen(stemp);
	a -= 6;
	for(i=0;i<a;i++) {

		stemp2 += stemp[i..i];
		

	}



a = to_int(stemp2);

if(a>=1000) {
	stemp = ((a-(a%1000))/1000)+"G ";
	a=a%1000;
	stemp += a+"Megs";
}
else stemp = a+"Megs";

return stemp;

}

status filter_mortals(object ob) {
if(ob->query_wiz()) return 0;
return 1;
}

void reset_vars() {

	new_summary = 0;
	old_summary = 0;
	rate = 0;
	short_rate = 0;
	short_time = 0;
	party_short_time = 0;
	party_summary = 0;
	party_old_summary = 0;
	party_rate = 0;
	party_short_rate = 0;
	active_flag = 1;

}


