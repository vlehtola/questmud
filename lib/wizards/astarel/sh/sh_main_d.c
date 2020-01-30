/* STRONGHOLD MAIN DAEMON by Astarel */

mapping room_data; /* ([ room_id : ([ room_exits ]); ([ chest_data ]); ([ guard_data ]); ([ door_data ]); sh_long_desc; sh_short_desc; owner, ]) */
static mapping hired_guards;

int stronghold_number;
string save_path;

void save_stronghold() { save_object(save_path); }

void reset(status arg) {

int temp_int;
	
	if(arg) return;
	
	room_data = ([ ]);	
	hired_guards = ([ ]); /* ([ guard_id : owner; type; level; items; name, ]) */
	
	save_path = file_name(this_object());
    	sscanf(save_path,"%s#%d",save_path,temp_int);
    	if(save_path[0..16] == "/data/stronghold/") {
		if(file_size(save_path+".o") != -1)restore_object(save_path);
   	}
  
}

void add_room_data(int room_id, mapping room_exits, mapping chest_data, mapping guard_data, mapping door_data, string sh_long_desc, string sh_short_desc, string owner) {
	
	if(room_data[room_id]) {
		room_data -= ([ room_id ]);
	}
	room_data += ([ room_id: room_exits; chest_data; guard_data; door_data; sh_long_desc; sh_short_desc; owner, ]);
	save_stronghold();
}

int get_free_guard_id() {
	string *temp;
	int i;
	
	temp = m_indices(hired_guards);
	i = sizeof(temp);
	i += 1;
	// Just to check if i is already reserved.
	while(member_array(i,temp) != -1) {
		i++;
	}
return i;
}

void add_hired_guard(int id, int type, int level, string *items, string name) {
	if(hired_guards[id]) id = get_free_guard_id();
	
	hired_guards += ([ id: type; level; items; name, ]);
}
void remove_hired_guard(int id) {
	if(hired_guards[id]) hired_guards -= ([ id ]);
}

mapping query_hired_guards() {
	return hired_guards;
}

mapping query_room_exits(int room_id) {
	if(room_data[room_id])return room_data[room_id,0];
	else return ([ ]);
}

mapping query_room_chest_data(int room_id) {
	
	if(room_data[room_id])return room_data[room_id,1];
	else return ([ ]);
}

mapping query_room_guard_data(int room_id) {
	
	if(room_data[room_id])return room_data[room_id,2];
	else return ([ ]);
}

mapping query_room_door_data(int room_id) {
	
	if(room_data[room_id])return room_data[room_id,3];
	else return ([ ]);
}

string query_room_long_desc(int room_id) {
	
	if(room_data[room_id])return room_data[room_id,4];
	return "DEFAULT ROOM LONG DESC";
}

string query_room_short_desc(int room_id) {
	
	if(room_data[room_id])return room_data[room_id,5];
	else return "DEFAULT ROOM SHORT DESC";
}

string query_room_owner(int room_id) {
	
	if(room_data[room_id])return room_data[room_id,6];
	else return "";
}


	

		
