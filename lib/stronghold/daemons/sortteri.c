#define EXPLIST "/daemons/explist"
#define SAVE_PATH "/data/stronghold/testidata"

string *list;
string *exps;
int *levels;
mapping concealed;

void reset(status arg) {
	
	list = EXPLIST->query_full_list();
	exps = EXPLIST->query_full_exps();
	levels = EXPLIST->query_full_levels();
	concealed = EXPLIST->query_full_concealed();
	
}
void renew_list() {
		list = EXPLIST->query_full_list();
		exps = EXPLIST->query_full_exps();
		levels = EXPLIST->query_full_levels();
		concealed = EXPLIST->query_full_concealed();
}




status remove_name(string name) {

int slot_number;
int temp_number;
	
	if(!name) {
			write("usage: remove_name name\n");
			return 1;
		}
		renew_list();
		
		if(member_array(name,list) == -1) {
				write("No such name in the list!\n");
				return 1;
			}
			
	temp_number = sizeof(list);
			
			
			for(slot_number= 0; slot_number < temp_number; slot_number++) {
				
							if(list[slot_number] == name) { 
									write("Match found!\n");
									break;
								}								
						}
			
			write("slotnumber: "+slot_number+" Found: "+list[slot_number]+" EXP: "+exps[slot_number]+" Lvl: "+levels[slot_number]+"\n");
			return 1;
			
			list -= ({ list[slot_number] });
			exps -= ({ exps[slot_number] });
			levels -= ({ levels[slot_number] });
			concealed -= ([ list[slot_number] ]);
			
			save_object(SAVE_PATH);
			
			
		}

		
		
		

	