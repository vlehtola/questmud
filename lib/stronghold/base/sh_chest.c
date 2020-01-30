// STRONGHOLD - CHEST  by Astarel 16.4.2004  //
#define ROOM environment(this_object())

// VARS

string *items;
string chest_label, chest_owner;
int chest_code,chest_type,chest_id;
status is_open,is_locked,is_jammed,is_attemp;
int local_weight;

// PROTOS
void save_eq();
void load_eq();
int get_storage_space(int type);
void save_chest();
string short();
void long();
// CODE

// set_ functions
void set_chest_id(int i) { chest_id = i; }
void set_chest_label(string str) { chest_label = str; }
void set_chest_owner(string str) { chest_owner = str; }
void set_chest_type(int i) { chest_type = i; }
void set_is_open(status i) { is_open = i; }
void set_items(string *str) { items = str; }

// query_ functions
int query_chest_id()	{ return chest_id; }
int query_chest_type()	{ return chest_type; }
string query_chest_label()	{ return chest_label; }
string query_chest_owner()	{ return chest_owner; }
status query_is_open()		{ return is_open; }
string *query_items()		{ return items; }

short() {
  string str;
  
  switch(chest_type) {
  	case 1 : str = "An oaken Coffer"; break;
  	case 2 : str = "A hardwood Chest";break;
  	case 3 : str = "A blackwood Warchest"; break;
  	default : str = "BUGGY!"; break;
}

  
  if(chest_label == 0 || chest_label == "0") str = str;
  else str = str+" labeled '"+chest_label+"'";
  if(is_open) str += " [open]";
  else if(!is_locked) str += " [unlocked]";
  return str;
}

void long() {
  object *ob;
  int i;
  write(short()+".\n");
  switch(chest_type) {
  	case 1 : write("Before you stands a wooden coffer. It is made out of oak and seems\n"+
		       "quite sturdy. The coffer is about half as big as your armspan in all\n"+ 
		       "directions, and weighs quite alot. The coffer has been reinforced by\n"+
		       "leather straps bolted into it. The coffer seems to be of quite high\n"+
		       "value.\n"); break;
	case 2 : write("A chest made of hardwood. The chest is cubical in form and is as big\n"+
		       "as your armspan. The chest has some metallic outlets at the extremities,\n"+
		       "indicating that it can be bolted down to the ground. The chest has\n"+
		       "iron straps attached to it, fortifying the make of the chest. The chest\n"+
		       "weighs alot and seems to be of high value.\n"); break;
	case 3 : write("The warchest is quite a construction. It is as high as your chest and\n"+
			"is made of the hardest, toughest wood found in the realm. It has been\n"+
			"fortified by mithril straps bolted to it, and has spikes on attached \n"+
			"to the extremities. The warchest has outlets on it allowing it to be\n"+
			"bolted to the ground. The chest seems to weigh enormously and is of\n"+
			"extremely high worth.\n"); break;
	default : write("BUGSOR!\n"); break;
}
  	 
  if(!is_open) return;
  ob = all_inventory(this_object());
  write("Items inside the chest:\n");
  while(i<sizeof(ob)) {
    if(ob[i]) write(" - "+ob[i]->short()+".\n");
    i += 1;
  }
  write(sizeof(ob)+" items inside the chest.\n");
}

status id(string str) {
  if((str == "chest") || (str == chest_label)) return 1;
}

void save_chest() {
	
	chest_id = ROOM->get_free_chest_id();
	ROOM->add_chest(chest_id, chest_label, chest_owner, chest_type, items);
	
}

// 4 types of chests.
int get_storage_space(int type) {
	
	switch(type) {
		case 1 : return 4;
		case 2 : return 6;
		case 3 : return 10;
	}
}

void debug_write(string str) {
	tell_object(find_player("astarel"),str);
}

void load_eq() {

	int i;
	for(i=0; i<sizeof(items); i++) {
		if(items[i] && file_size("/"+items[i]+".c") != -1) {
			debug_write(":: Cloning "+items[i]+"\n");
			move_object(clone_object("/"+items[i]),this_object());
			
		}
	}
	items = ({ });
	if(chest_id)ROOM->remove_chest(chest_id);
	return;
}

status can_put_and_get(string str) {
  object *ob;
  int max_eqs;
  
  max_eqs = get_storage_space(chest_type);
  ob = all_inventory(this_object());

  if(sizeof(ob) > (max_eqs - 1)) {
  	write("Chest is full.\n");
     return 0;
}

  if(is_open) { 
    return 1;   
    }
    if(!is_open) {
    	write("Chest is closed, open it first!\n");
    	return 0;
}

    
  }		

void save_eq() {
	
int i,tmp;
object *ob;
string str;
	
	items = ({ });
	ob = all_inventory(this_object());
	
	for(i=0;i<sizeof(ob);i++) {
		
		str = file_name(ob[i]);
    		if(str) sscanf(str,"%s#%d",str,tmp);
		items += ({ str, });
		destruct(ob[i]);
	}
	save_chest();	
}	

void reset(status arg) {
	if(arg) return;
	items = ({ });
	chest_label = "";
	chest_owner = "";
	chest_code = 0;
	chest_type = 1;
	is_open = 0;
	is_locked = 1;
	if(!chest_owner)is_open = 1;

	
	
}

status query_is_chest() { return 1; }

status chest_close() {
  
string dummy;
int tempid;
/*
	if(sscanf(arg, "ches%s", dummy) != 1) {
    		if(arg != chest_label) return 1;
  	}
  	
  	if(!arg || present(arg) != this_object()) return 1;
*/
	if(!is_open) {
    		write(short()+" is already closed.\n");
    	return 1;
  	}
  	
  	write("You close "+short()+".\n");
  	is_open = 0;
  	is_locked = 1;
  
  	chest_owner = this_player()->query_real_name();
  
  	save_eq();
  
  	return 1;
}

status chest_open() {
  string dummy;

 /*
  if(sscanf(arg, "ches%s", dummy) != 1) {
    if(arg != chest_label) return 1;
  }
  if(present(arg) != this_object()) return 1;

*/

  if(is_open) {
    write(short()+" is already open.\n");
    return 1;
  }
 	if(is_locked == 1 && this_player()->query_real_name() != chest_owner) {
		write("Chest is locked!\n");
		return 1;
	}  

  if(is_locked == 0 || this_player()->query_real_name() == chest_owner) {
  	write("You open "+short()+".\n");
  	say(capitalize(this_player()->query_name())+" opens "+short()+".\n");
  	is_open = 1;
  	is_locked = 0;
  	load_eq();
  	return 1;
	}

}


init() {
  add_action("chest_label", "label");
}
void chest_label(string str) {
	
	chest_label = str;
}


add_weight(i) {
  return 1;
}

query_weight() { return local_weight; }