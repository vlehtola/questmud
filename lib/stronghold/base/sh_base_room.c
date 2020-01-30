/* STRONGHOLD - BASIC_ROOM by Astarel 16.4.2004 */

#define BASIC_ROOM "/stronghold/basic/sh_basic_room"
#define COPIER "/stronghold/daemons/copier"
#define CHEST "/stronghold/base/sh_chest"
#define GUARD "/stronghold/base/sh_guard"

#define DEFAULT_PATH "/data/stronghold/stronghold_"

#define CHEST_LABEL(X)		chest_data[X,0]
#define CHEST_OWNER(X)		chest_data[X,1]
#define CHEST_TYPE(X)		chest_data[X,2]
#define CHEST_ITEMS(X)		chest_data[X,3]

#define GUARD_OWNER(X)		guard_data[X,0]
#define GUARD_FRIENDS(X)	guard_data[X,1]
#define GUARD_TYPE(X)		guard_data[X,2]
#define GUARD_LEVEL(X)		guard_data[X,3]
#define GUARD_BLOCKS(X)		guard_data[X,4]
#define GUARD_ITEMS(X)		guard_data[X,5]
#define GUARD_AGGRESSIVE(X)	guard_data[X,6]
#define GUARD_NAME(X)		guard_data[X,7]

#define DOOR_OWNER(X)		door_data[X,0]
#define DOOR_ALLOWED(X)		door_data[X,1]
#define DOOR_TYPE(X)		door_data[X,2]

inherit "room/room";

// vars
mapping room_exits; /* ([ exit : path, ]); */
mapping chest_data; /* ([ chest_id: label; owner; chest_type; ({ chest_items }), ]); */
mapping guard_data; /* ([ guard_id: owner; ({ friend_list }); type ; level ; ({ block_dirs }); ({ items }); is_aggressive;guard_name ]); */
mapping door_data;  /* ([ DIR : owner; ({ allowed }); type, }) */
static string *open_doors; /* Open doors */
static string *allowed_exits; /* allowed exits when building new rooms */
string save_file; /* path to room's save_file */
string owner; /* owner of the room */
string ruler; /* ruler of the stronghold */
static int sh_number;
string sh_long_desc;
string sh_short_desc;
int sh_room_light;
int room_id;

// protos
void add_chest(int id, string label, string owner, int type, string *t_items);
void add_door(string dir,int type);
void add_guard(int id, string owner, string *friends_l, int type, int level, string *block_dirs, string *items, status is_aggressive,string guard_name);
void add_room_exit(string exit,string path);
void build_new_room(string str);
status chest_main(string str);
void close_door(string str, status flag);
void debug_write(string msg);
status door_main(string str);
string get_door_type(int type);
int get_free_chest_id();
int get_free_guard_id();
int get_room_number();
string get_save_path();
varargs status guard_help(string str);
status guard_main(string str);
status is_chest(object ob);
status is_guard(object ob);
void make_chests();
void make_doors();
void make_guards();
void open_door(string str,status flag);
void print_hired_guards();
void remove_chest(int id);
void remove_door(string dir,status flag);
void remove_guard(int id);
status room_main(string str);

void save_room() {
		call_other("/data/stronghold/stronghold_"+sh_number+"/daemons/sh_main_d","add_room_data",room_id,room_exits,chest_data,guard_data,door_data,sh_long_desc,sh_short_desc,owner);
}

// set-functions
void set_ruler(string str) { ruler = str; }
void set_save_file(string str) { save_file = str; }
void set_owner(string str) { owner = str; }

// query-functions
string query_ruler() { return ruler; }
string query_save_file() { return save_file; }
string query_owner() { return owner; }
int query_is_stronghold() { return 1; }	

void debug_write(string msg) {
	tell_object(find_player("astarel"),":: "+msg+" ::\n");
}

void add_door(string dir,int type,status flag) {
string *temp;
string new_room;
int i_temp;

	if(!dir) return;
	if(!type) return;
		
	new_room = "";
	temp = m_indices(door_data);
	
	if(member_array(dir,temp) != -1) {
		write("there is already a door to "+dir+"\n");
		return;
	}
	
	temp = this_object()->query_dest_dir();
	
	if(member_array(dir,temp) == -1) {
		write("there is no such exit!\n");
		return;
	}
	if(member_array(dir,allowed_exits) == -1) {
		write("You cant put a door to "+dir+"\n");
		return;
	}
	
	door_data += ([ dir: this_player()->query_real_name(); ({ }); type, ]);
	//write("Building new "+get_door_type(type)+" door to "+dir+"\n");
	new_room = this_object()->query_valid_dir(dir);
	
	sscanf(new_room,"%s#%d",new_room,i_temp);
	
	switch(dir) {
		case "north" : dir = "south"; break;
		case "south" : dir = "north"; break;
		case "east"  : dir = "west"; break;
		case "west"  : dir = "east"; break;
		case "northwest" : dir = "southeast"; break;
		case "southeast" : dir = "northwest"; break;
		case "northeast" : dir = "southwest"; break;
		case "southwest" : dir = "northeast"; break;
		case "up" : dir = "down" ; break;
		case "down" : dir = "up" ; break;
		default : dir = "BUG"; break;
	}
	
	if(!flag)call_other(new_room,"add_door",dir,type,1);	
	make_doors();
	save_room();
	
}

void remove_door(string dir,status flag) {
string *temp;	
string new_room;
int i_temp;

	if(!dir)return;
	
	temp = m_indices(door_data);
	
	if(member_array(dir,temp) == -1) {
		write("There is no door in "+dir+"\n");
		return;
	}
	
	new_room = this_object()->query_valid_dir(dir);
	
	add_exit(dir,room_exits[dir]);
	
	sscanf(new_room,"%s#%d",new_room,i_temp);
	
		switch(dir) {
		case "north" : dir = "south"; break;
		case "south" : dir = "north"; break;
		case "east"  : dir = "west"; break;
		case "west"  : dir = "east"; break;
		case "northwest" : dir = "southeast"; break;
		case "southeast" : dir = "northwest"; break;
		case "northeast" : dir = "southwest"; break;
		case "southwest" : dir = "northeast"; break;
		case "up" : dir = "down" ; break;
		case "down" : dir = "up" ; break;
		default : dir = "BUG"; break;
	}
	
	if(!flag)call_other(new_room,"remove_door",dir,1);
	
	door_data -= ([ dir ]);
	save_room();
}

string get_door_type(int type) {
	
	switch(type) {
		
		case 1 : return "wooden"; break;
		case 2 : return "steel reinforced wooden"; break;
		case 3 : return "steel"; break;
		default : return "bugging";break;
	}
}

void make_doors() {
string *temp;
string door_desc;
int i;
string tmp;

	if(!door_data)return;
	door_desc = "\n";
	temp = m_indices(door_data);
	
	// Lets make the doors!
	for(i = 0;i<sizeof(temp);i++) {
		
		if(member_array(temp[i],open_doors) != -1) {
			door_desc += "There is a open "+get_door_type(DOOR_TYPE(temp[i]))+" door leading to "+temp[i]+"\n";
		}
		else { 	door_desc += "There is a closed "+get_door_type(DOOR_TYPE(temp[i]))+" door leading to "+temp[i]+"\n";
			remove_exit(temp[i]);
		}
	}
		
	set_long(sh_long_desc+door_desc);
	set_short(sh_short_desc+door_desc);
	
}

void open_door(string str,status flag) {
string *temp;
string str_temp;
	
	if(!str)return;
	
	temp = m_indices(door_data);
	
	if(member_array(str,temp) == -1) {
		write("there are no such door!\n");
		return;
	}
	
	if(member_array(str,open_doors) != -1) {
		write(str+" door is already open!\n");
		return;
	}

	open_doors += ({ str });
	add_exit(str,room_exits[str]);
	make_doors();
		str_temp = str;
		
		switch(str) {
		case "north" : str = "south"; break;
		case "south" : str = "north"; break;
		case "east"  : str = "west"; break;
		case "west"  : str = "east"; break;
		case "northwest" : str = "southeast"; break;
		case "southeast" : str = "northwest"; break;
		case "northeast" : str = "southwest"; break;
		case "southwest" : str = "northeast"; break;
		case "up" : str = "down" ; break;
		case "down" : str = "up" ; break;
		default : str = "BUG"; break;
	}
	// so the door opens in the room where you are going..
	if(!flag)call_other(this_object()->query_valid_dir(str_temp),"open_door",str,1);
}

void close_door(string str,status flag) {
	
	string str_temp;
	if(!str) return;
	
	if(member_array(str,open_doors) == -1) {
		write("There are no such door, or that door is already closed!\n");
		return;
	}
	
	str_temp = str;
	switch(str) {
		case "north" : str = "south"; break;
		case "south" : str = "north"; break;
		case "east"  : str = "west"; break;
		case "west"  : str = "east"; break;
		case "northwest" : str = "southeast"; break;
		case "southeast" : str = "northwest"; break;
		case "northeast" : str = "southwest"; break;
		case "southwest" : str = "northeast"; break;
		case "up" : str = "down" ; break;
		case "down" : str = "up" ; break;
		default : str = "BUG"; break;
	}
	if(!flag)call_other(this_object()->query_valid_dir(str_temp),"close_door",str,1);
	
		remove_exit(str_temp);	
	open_doors -= ({ str_temp });
	make_doors();
}

void add_chest(int id, string label, string owner, int type, string *t_items) {

	if(chest_data[id]) chest_data -= ([ id ]);
	chest_data += ([ id: label; owner; type; t_items, ]);
	save_room();
}		

void add_guard(int id, string owner, string *friends_l, int type, int level, string *block_dirs, string *items, status is_aggressive,string guard_name) {
	
	if(guard_data[id]) guard_data -= ([ id ]);
	guard_data += ([ id: owner; friends_l; type; level; block_dirs; items; is_aggressive;guard_name, ]);
	save_room();
}

void remove_guard(int id) {
	
	if(guard_data[id]) {
		guard_data -= ([ id ]);
		save_room();
	}
	
}

void remove_chest(int id) {
	
	
	if(chest_data[id]) {
		debug_write("Deleting chest: id: "+id);
		chest_data -= ([ id ]);
		save_room();
	}
	
}

int get_free_chest_id() {
	string *temp;
	int i;
	
	temp = m_indices(chest_data);
	i = sizeof(temp);
	i += 1;
	// Just to check if i is already reserved.
	while(member_array(i,temp) != -1) {
		i++;
	}
return i;
}

int get_free_guard_id() {
	string *temp;
	int i;
	
	temp = m_indices(guard_data);
	i = sizeof(temp);
	i += 1;
	// Just to check if i is already reserved.
	while(member_array(i,temp) != -1) {
		i++;
	}
return i;
}

void make_chests() {
	int i;
	string *temp;
	string *items;
	object ob;
	
	temp = m_indices(chest_data);
	if(sizeof(temp) == 0 || !temp) return;
	
	for(i = 0; i < sizeof(temp); i++) {
		ob = clone_object(CHEST);
		
		ob->set_chest_id(temp[i]);
		ob->set_chest_label(CHEST_LABEL(temp[i])) ;
		ob->set_chest_owner(CHEST_OWNER(temp[i])) ;
		ob->set_chest_type(CHEST_TYPE(temp[i])) ;
		ob->set_items(CHEST_ITEMS(temp[i])) ;
		ob->set_is_open(0);
		move_object(ob,this_object());
	}
	
}

void make_guards() {
	int i;
	string *temp;
	string *items;
	object ob;
	
	temp = m_indices(guard_data);
	if(sizeof(temp) == 0 || !temp) return;
	
	for(i = 0; i < sizeof(temp); i++) {
		ob = clone_object(GUARD);
		
		ob->set_owner(GUARD_OWNER(temp[i]));
		ob->set_guard_friends(GUARD_FRIENDS(temp[i]));
		ob->set_guard_block_dirs(GUARD_BLOCKS(temp[i]));
		ob->set_guard_level(GUARD_LEVEL(temp[i]));
		ob->set_guard_aggressive(GUARD_AGGRESSIVE(temp[i]));
		ob->set_guard_type(GUARD_TYPE(temp[i]));
		ob->set_guard_items(GUARD_ITEMS(temp[i]));
		ob->set_guard_name(GUARD_NAME(temp[i]));
		ob->set_guard_id(temp[i]);
		ob->guard_reset();
		move_object(ob,this_object());
	}
	
}

// Finds out a free room-number.
int get_room_number() {
	int i;
	string str_temp,str_temp2;
  	
	str_temp = file_name(this_object());
   	sscanf(str_temp, "%s/stronghold_%d/room%d", str_temp2, sh_number,i);
  
  	i = 1;
  	while(file_size(DEFAULT_PATH+sh_number+"/rooms/room"+i+".c") != -1) {
    		i += 1;
  	}
  	//debug_write("NEW ROOM, nro "+i);
  	
  	return i;
}
// Gets save path;
string get_save_path() {
	string path_file;
	int tmp;
	
	path_file = file_name(this_object());
	sscanf(path_file,"%s#%d",path_file,tmp);
		
	return path_file;
}

void remove_room(string str) {
string *exit_list;
string temp;
object *obs;
int tmp;
object ob;

	if(!str) return;
	
	exit_list = this_object()->query_dest_dir();
	
	if(member_array(str,exit_list) == -1) {
		write("No such exit.\n");
		return;
	}
	// check check double-check
	if(!room_exits[str]) {
		write("No such exit.\n");
		return;
	}
		
	if(str == "enter" || str == "out") {
		write("Nice try m8, no can doo.\n");
		return;
	}
	
	// lets check if the room contains any objects
	obs = all_inventory(find_object(this_object()->query_valid_dir(str)));
	if(sizeof(obs) > 0) {
		write("The room contains something and therefore cannot be removed.\n");
		return;
	}
		
	temp = this_object()->query_valid_dir(str);
	sscanf(temp,"%s#%d",temp,tmp);
		
	room_exits -= ([ str ]);
	remove_exit(str);

	// TODO: Check if the room is empty.
	
	ob = find_object(temp);
	if(ob) destruct(ob);	
	if(file_size(temp+".c") != -1) rm(temp+".c");
	
	save_room();
	
}
		
// Function that builds new room.
void build_new_room(string str) {
	
	string new_path;
	string tmp,tmp2;
	string back_exit;
	int new_number;
	string temp;
	int i_tmp,i_tmp2;
	
	if(!str)return;

	new_number = get_room_number();
	new_path = DEFAULT_PATH+sh_number+"/rooms/room"+new_number;
	
	if(room_exits[str]) {
		write("Exit: "+str+" is already reserved!\n");
		return;
	}
	temp = file_name(this_object());
	sscanf(temp,"%s#%d",temp,tmp);
		
	i_tmp = strlen(temp);
	i_tmp2 = i_tmp - 8;
	//debug_write("build_new_room temp: "+temp[i_tmp2..i_tmp]);
		if(temp[i_tmp2..i_tmp] == "entrance") {
			write("Go inside, TWAT!\n");
			return;
		}
	if(member_array(str,allowed_exits) == -1 ) {
				write("Exit: "+str+" is not a valid exit!\n");
				return;
			}
	
	COPIER->copy_file(BASIC_ROOM+".c",new_path+".c");
	
	switch(str) {
		case "north" : back_exit = "south"; break;
		case "south" : back_exit = "north"; break;
		case "east"  : back_exit = "west"; break;
		case "west"  : back_exit = "east"; break;
		case "northwest" : back_exit = "southeast"; break;
		case "southeast" : back_exit = "northwest"; break;
		case "northeast" : back_exit = "southwest"; break;
		case "southwest" : back_exit = "northeast"; break;
		case "up" : back_exit = "down" ; break;
		case "down" : back_exit = "up" ; break;
		default : back_exit = "switch default value returned, report bug to astarel"; break;
	}
		
	add_room_exit(str,new_path);
	add_exit(str,new_path);
	
	tmp2 = new_path;	
	new_path = file_name(this_object());
	sscanf(new_path,"%s#%d",new_path,tmp);
	
	call_other(tmp2,"add_room_exit",back_exit,new_path);
	call_other(tmp2,"set_ruler",ruler);
	
	save_room();	
}	

// To add room exits
void add_room_exit(string exit,string path) {
	
	if(!exit || !path) return;
	
	room_exits += ([ exit : path ]);
	save_file = get_save_path();
	save_room();
	
	return;
}

status is_chest(object ob) {
	if(ob->query_is_chest())return 1;
	return 0;
}

// syntax: chest <cmd> || chest <cmd> <arg> || chest <#> <cmd> <arg>
status chest_main(string str) {
object *chests;
object chest;
int i,i_arg;
string *temp_array;
string s_arg,s_arg2;
	
	if(!str) {
		write("Usage: type 'chest help' for instructions\n");
		return 1;
	}
	
	if(str == "help") {
		
		return 1;
	}		      
	
	chests = all_inventory(this_object());
	chests = filter_array(chests,"is_chest");
	
	if(sscanf(str,"%D %s %s",i_arg,s_arg,s_arg2) == 3) {
		
		if(i_arg == 0) {
			write("nice try!\n");
			return 1;
		}
		
		i = i_arg - 1;
		if(sizeof(chests) < (i+1)) {
			write("No such chest!!\n");
			return 1;
		}
		if(chests[i])chest = chests[i];
	}
	
	
	if(sizeof(chests) == 0) {
		write("NO CHESTS!\n");
		return 1;
	}
	
	
	else if(sscanf(str,"%D %s",i_arg,s_arg) == 2) {
		if(i_arg == 0) {
			write("nice try!\n");
			return 1;
		}
		i = i_arg - 1;
		if(sizeof(chests) < (i+1)) {
			write("no such chest!\n");
			return 1;
		}
		if(chests[i])chest = chests[i];
	}
	
	else if(sscanf(str,"%s %s",s_arg,s_arg2) == 2) {
		i = 0;
		chest = chests[i];
	}
	else if (sscanf(str,"%s",s_arg) == 1) {
		i = 0;
		chest = chests[i];
	}
			
	debug_write("::i: "+i+" s_arg: "+s_arg+", s_arg2: "+s_arg2+" \n");
	
	switch(s_arg) {
		case "open" : 	write("Trying to open chest!\n");
				if(chest)chest -> chest_open();
				 break;
		case "close" : write("trying to close chest!\n");
				if(chest)chest -> chest_close();
				break;
				
		case "label" :	if(!s_arg2) {
					write("usage: chest # label <to what>\n");
					break;
				}
				if(chest)chest -> set_chest_label(s_arg2);
				break;
		case "seal" :   write("To come!\n");
				break;
		
		case "unseal" : write("TO come!\n");
				break;
				
		default : write("BUGSOR!\n"); break;
		}
		
	
	return 1;
	
}

varargs status guard_help(string str) {
	
	if(!str) {
		write(".-------------------------------------------------------.\n"+
		      "| Command:          info:                               |\n"+
		      "+-------------------------------------------------------+\n"+
		      "| help <cmd>        W/o argument, this help, with cmd   |\n"+
		      "|                   more information about cmd          |\n"+
		      "| block <dir>       Guard starts blocking <dir>         |\n"+
		      "|                   If <dir> is already blocked, guard  |\n"+
		      "|                   stops blocking it.                  |\n"+
		      "| hire <id>         Positions guard to this room.       |\n"+
		      "| sack <id>	   Releases guard from this room and   |\n"+
		      "|                   returns it to the barracks.         |\n"+
		      "| friend <name>     Guard starts to like <name>         |\n"+
		      "|		   if <name> is already in guards list,|\n"+
		      "|                   it will be removed.                 |\n"+
		      "| agro <on/off>     on : aggressive                     |\n"+
		      "|                   off : Incarnation of mother theresa |\n"+
		      "+-------------------------------------------------------+\n"+
		      "| Syntax: guard <cmd> <arg>                             |\n"+
		      "| Report bugs, ideas, typos to astarel                  |\n"+
		      "'-------------------------------------------------------'\n");
		}
	return 1;
}

status is_guard(object ob) {
	if(ob->query_is_guard() == 1) return 1;
	return 0;
}

status guard_main(string str) {
object *guards;
object vartija;
int i,i_arg;
string *temp_array;
string s_arg,s_arg2;
string g_name;
	
	if(!str) {
		write("Usage: type 'guard help' for instructions\n");
		return 1;
	}
	
	if(str == "help") {
		
		guard_help();
		
		return 1;
	}		      
	
	guards = all_inventory(this_object());
	guards = filter_array(guards,"is_guard");
	
	if(sizeof(guards) == 0) {
		write("NO GUARDS!\n");
		return 1;
	}
	
	
	if(sscanf(str,"%D %s %s",i_arg,s_arg,s_arg2) == 3) {
		
		if(i_arg == 0) {
			write("nice try!\n");
			return 1;
		}
		
		i = i_arg - 1;
		if(sizeof(guards) < (i+1)) {
			write("No such guard!\n");
			return 1;
		}
		if(guards[i])vartija = guards[i];
	}
	else if(sscanf(str,"%s %s %s",g_name,s_arg,s_arg2) == 3) {
		
		for( i=0;i<sizeof(guards);i++) {
			if(lower_case(guards[i]->query_guard_name()) == lower_case(g_name)) {
				if(guards[i])vartija = guards[i];
				break;
			}
		}		
	}
	
	else if(sscanf(str,"%s %s",s_arg,s_arg2) == 2) {
		i = 0;
		vartija = guards[i];
	}
	
	
	debug_write("::i: "+i+" s_arg: "+s_arg+", s_arg2: "+s_arg2+" \n");
	
	switch(s_arg) {
		case "help" : 	write ("To come!");
				 break;
		case "block" : 
				if(!s_arg2) {
					write("usage: guard block <direction>\n");
					break;
				}
				temp_array = vartija -> query_block_dirs();
				if(member_array(s_arg2,temp_array) != -1) {
					vartija->remove_block_dir(lower_case(s_arg2));
					break;
				}
				vartija->add_block_dir(lower_case(s_arg2));
				break;
		case "sack" :   
				write("Sacking guard "+i+" called: "+vartija->query_guard_name()+" ID:"+vartija->query_guard_id()+"\n");
				call_other("/data/stronghold/stronghold_"+sh_number+"/daemons/sh_main_d","add_hired_guard",vartija->query_guard_id(),vartija->query_guard_type(),vartija->query_guard_level(),vartija->query_guard_items(),vartija->query_guard_name());
				remove_guard(vartija->query_guard_id());
				destruct(vartija);
				break;
		
		case "friend" : if(!s_arg2) {
					write("usage: guard friend <name>\n");
					break;
				}
				temp_array = vartija->query_guard_friends();
				if(member_array(s_arg2,temp_array) != -1) {
					write("Removing "+s_arg2+" from my friends-list!\n");
					vartija->remove_friend(lower_case(s_arg2));
					break;
				}
				write("Adding "+s_arg2+" to my friends-list!\n");
				vartija->add_friend(lower_case(s_arg2));
				break;
				

		case "agro" :  if(!s_arg2) {
					write("usage: guard agro on / off\n");
					break;
				}
				if(s_arg2 == "on") vartija->set_guard_aggressive(1);
				else if(s_arg2 == "off") vartija->set_guard_aggressive(0);
				else write("Usage: guard agro on / off\n");
				break;
				
		default : write("BUGSOR!\n"); break;
		}
		
	
	return 1;
	
}

init() {
int i;
string *temp;	
	::init();
		add_action("chest_main","chest");
		add_action("guard_main","guard");
		add_action("door_main","door");
		add_action("room_main","room");
		
	// Adds room-exits	
	temp = m_indices(room_exits);
	if(sizeof(temp) > 0) {
		
		for(i=0; i<sizeof(temp);i++) {
			add_exit(temp[i],room_exits[temp[i]]);
		}
	}
	make_doors();
	
		
}

status door_main(string str) {

string s_arg,s_arg2;

	if(!str) {
		write("usage: door <open/close> <dir>\n");
		return 1;
	}
	
	if(sscanf(str,"%s %s",s_arg,s_arg2) != 2) {
		write("usage: door <open/close> <dir>\n");
		return 1;
	}
	
	switch(s_arg) {
		case "open" : 	write("trying to open "+s_arg2+" door\n");
				open_door(s_arg2,0);
				break;
		case "close" :  write("trying to close "+s_arg2+" door\n");
				close_door(s_arg2,0);
				break;
		}
		
return 1;
}
	
	

void print_hired_guards() {
	
mapping mapp;
string *temp;
string *tampp;
int i;

	mapp = call_other("/data/stronghold/stronghold_"+sh_number+"/daemons/sh_main_d","query_hired_guards");
	if(!mapp)return;
	
	temp = m_indices(mapp);
	
	write(".------------ AVAILABLE GUARDS --------------.\n"+
	      "| ID: TYPE: LEVEL: AMOUNT OF ITEMS: NAME:    |\n");
	
	for(i=0;i<sizeof(temp);i++) {
		
		write("| "+temp[i]+"  "+mapp[temp[i],0]+" "+mapp[temp[i],1]+" "+sizeof(mapp[temp[i],2])+" "+mapp[temp[i],3]+" |\n");
		
	}
return;
}

// Main function
status room_main(string str) {
string s_arg,s_arg2;
string *temp;
int i_arg;
mapping mapp;
object ob;

	if(!str) {
		write("Type 'room help' to get more information.\n");
		return 1;
	}
	if(str == "help") {
		write("-=-=-=-=-=-=-=-=-=-=-=-=- ROOM HELP -=-=-=-=-=-=-=-=-=-=-=-=-\n"+
					" Command:						Info:					\n"+
					" build	<dir>					builds new room to <dir>\n"+
					" destruct <dir>			destructs room from <dir>\n"+
					" list								list hireable guards\n"+
					" hire <ID>						hires guard with <id> into this room\n"+
					"	start								makes this room to your startpoint\n"+
					" door <dir> <type>		builds new <type> of door to <dir>\n"+
					" bash <dir>					bashes <dir> door\n");
					
		return 1;
	}
	
	if(str == "list") {
		print_hired_guards();
		return 1;
	}
	
	if(str == "start") {
		write("cmd: room start, not working.\n");
		return 1;
	}
	else if(sscanf(str,"%s %s %d",s_arg,s_arg2,i_arg) == 3) {
		//debug_write("s_arg: "+s_arg+" s_arg2: "+s_arg2+" i_arg: "+i_arg);
	}
	
	else if(sscanf(str,"%s %d",s_arg, i_arg) == 2) {
		//debug_write("s_arg: "+s_arg+" i_arg: "+i_arg);
	}	
	else if(sscanf(str,"%s %s",s_arg,s_arg2) == 2) {
		//debug_write("s_arg: "+s_arg+" s_arg2: "+s_arg2);
	}
	
	if(!s_arg) {
		write("cmd: room missing s_arg!\n");
		return 1;
	}
	
	switch(s_arg) {
		
		case "build" : if(!s_arg2) {
					write(":: cmd- room build, no s_arg2! ::\n");
					break;
				}
				write("building new room to"+s_arg2+"\n");
				build_new_room(s_arg2);
				break;
							
		case "destruct" : if(!s_arg2) {
					write(":: cmd - room destruct, no s_arg2 ::\n");
					break;
				}
				write("Destructing room from "+s_arg2+"\n");
				remove_room(s_arg2);
				break;
				
			
		case "hire" :  
				i_arg = to_int(s_arg2);
				/*
				if(!i_arg) {
					write("NANANA!\n");
					break;
				}
				*/
				mapp = call_other("/data/stronghold/stronghold_"+sh_number+"/daemons/sh_main_d","query_hired_guards");
				temp = m_indices(mapp);
				if(sizeof(temp) <= 0) {
					write("NO GUARDS TO HIRE!\n");
					break;
				}
				if(member_array(i_arg,temp) == -1) {
					write("NO SUCH GUARD TO HIRE!\n");
					break;
				}
				ob = clone_object(GUARD);
				ob->set_owner(this_player()->query_real_name());
				ob->set_guard_level(mapp[temp[i_arg],1]);
				ob->set_guard_type(mapp[temp[i_arg],0]);
				ob->set_guard_items(mapp[temp[i_arg],2]);
				ob->set_guard_name(mapp[temp[i_arg],3]);
				ob->guard_reset();
				move_object(ob,this_object());
				ob->save_guard();
				//add_guard(get_free_guard_id(),this_player()->query_real_name(),({ }),mapp[temp[i_arg],0],mapp[temp[i_arg],1], ({ }), mapp[temp[i_arg],2], 0, mapp[temp[i_arg],3]);
				call_other("/data/stronghold/stronghold_"+sh_number+"/daemons/sh_main_d","remove_hired_guard",temp[i_arg]);
				break;
				
				
		 	
		case "door" : 
				
				if(!s_arg2) {
					write("cmd: room door missing s_arg2!\n");
					break;
				}
				if(!i_arg) {
						write("cmd: room door missing i_arg!\n");
						break;
					}
					
				write("Building new "+get_door_type(i_arg)+" door to "+s_arg2+"\n");
				add_door(s_arg2,i_arg,0);
				break;
				
		case "bash" : if(!s_arg2) {
					write("door bash, no s_arg2!\n");
					break;
				}
				
				write("bashing door "+s_arg2+"\n");
				remove_door(s_arg2,0);
				break;
			
		case "owner" : if(!s_arg2) {
				write("owner, no s_arg2!\n");
				break;
				}
				write("Setting rooms owner to: "+s_arg2+"\n");
				set_owner(s_arg2);
				save_room();
				break;
		}
	
		
return 1;
}

reset(arg) {
string dir_temp;
string *temp;
int temp_int;
int i;

	if(arg) return;

	sh_room_light = 3;
	// allowed exits
	allowed_exits = ({"north", "northeast", "east", "southeast", "south", "southwest", "west", "northwest","up", "down",});
	
	room_exits = ([ ]);
	chest_data = ([ ]);
	guard_data = ([ ]);
	door_data = ([ ]);
	open_doors = ({ });
	
	sh_short_desc = "Basic room short desc!";
	sh_long_desc = "Basic room long desc!";
	
	// Restores room-data
	dir_temp = file_name(this_object());
   	if(sscanf(dir_temp, "%s/stronghold_%d/rooms/room%d#%d", dir_temp, sh_number,i,temp_int)) { }
   	else { if(sscanf(dir_temp, "%s/stronghold_%d/rooms/entrance#%d", dir_temp, sh_number,temp_int)) i=0; }
   	room_id = i;
	dir_temp = file_name(this_object());
    	sscanf(dir_temp,"%s#%d",dir_temp,temp_int);
    	
	if(dir_temp[0..16] == "/data/stronghold/") {
		debug_write("resetting room "+file_name(this_object())+" SH_NUMBER:"+sh_number+" room number:"+i+"\n");
  		
  		room_exits = call_other("/data/stronghold/stronghold_"+sh_number+"/daemons/sh_main_d","query_room_exits",i);
  		chest_data = call_other("/data/stronghold/stronghold_"+sh_number+"/daemons/sh_main_d","query_room_chest_data",i);
  		guard_data = call_other("/data/stronghold/stronghold_"+sh_number+"/daemons/sh_main_d","query_room_guard_data",i);
  		door_data = call_other("/data/stronghold/stronghold_"+sh_number+"/daemons/sh_main_d","query_room_door_data",i);
  		owner = call_other("/data/stronghold/stronghold_"+sh_number+"/daemons/sh_main_d","query_room_owner",i);
  		sh_long_desc = call_other("/data/stronghold/stronghold_"+sh_number+"/daemons/sh_main_d","query_room_long_desc",i);
  		sh_short_desc = call_other("/data/stronghold/stronghold_"+sh_number+"/daemons/sh_main_d","query_room_short_desc",i);
  	}	
  		
   	
	temp = m_indices(room_exits);
	if(sizeof(temp) > 0) {
		
		for(i=0; i<sizeof(temp);i++) {
			//debug_write("Adding exit: "+temp[i]+" "+room_exits[temp[i]]);
			add_exit(temp[i],room_exits[temp[i]]);
		}
	}
	
	make_chests();
	make_guards();
	make_doors();

  
 	set_light(sh_room_light);
 	short_desc = sh_short_desc;
	long_desc  = sh_long_desc;
  
  	property = allocate(1);
  	property[0] = "no_summon";
    
}