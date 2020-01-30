/* STRONGHOLD - GUARD by Astarel 19.4.2004 */

inherit "obj/monster";

// DEFINES
#define ROOM environment(this_object())
#define KIRVES "/wizards/astarel/sh/axe.c"

// VARS
string *friends; // Array of friends ({ "me", "you", "him", "her",..});
string *block_dirs; // Array of blocked directions ({ "south", "up", "north", jne, });
string *items; // Array of items 
int guard_level,guard_id;
string owner;
string ruler;
static string *allowed_dirs;
status guard_aggressive;
int guard_type;
string guard_name;

// PROTOS
void reset(status arg);
void catch_tell(string str);
void level_up();
void equip_items();
void add_friend(string str);
void remove_friend(string str);
status block_move();
void add_block_dir(string str);
void remove_block_dir(string str);
void save_guard();
void guard_main();

// Set-functions
void set_ruler(string str) { ruler = str; }
void set_owner(string str) { owner = str; }
void set_guard_level(int i) { guard_level = i; }
void set_guard_aggressive(status i) { guard_aggressive = i; }
void set_guard_friends(string *str) { friends = str; }
void set_guard_block_dirs(string *str) { block_dirs = str; }
void set_guard_items(string *str) { items = str; }
void set_guard_type(int i) { guard_type = i; }
void set_guard_name(string str) { guard_name = str; set_short(capitalize(guard_name)+" the guard."); set_alt_name(lower_case(guard_name)); }
void set_guard_id(int id) { guard_id = id; }



// Query-functions
string query_ruler() { return ruler; }
string query_owner() { return owner; }
int query_guard_level() { return guard_level; }
status query_guard_aggressive() { return guard_aggressive; }
status query_is_guard() { return 1; }
string *query_guard_items() { return items; }
string *query_block_dirs() { return block_dirs; }
string *query_guard_friends() { return friends; }
string query_guard_name() { return guard_name; }
int query_guard_id() { return guard_id; }
int query_guard_type() { return guard_type; }

// CODE

void save_guard() {
int i;	

	i = environment(this_object())->get_free_guard_id();
	environment(this_object())->add_guard(i, owner, friends, guard_type, guard_level, block_dirs, items, guard_aggressive,guard_name);
}


void reset(status arg) {
	::reset(arg);
	if(arg) return;
	
	friends = ({ });
	block_dirs = ({ });
	items = ({ });
	guard_level = 1;	
	owner = "";
	ruler = "";
	guard_type = 0;
	guard_aggressive = 0;
	guard_name = "";
	
	allowed_dirs = ({ "south", "north", "east", "west", "northwest", "northeast", "southeast", "southwest", "up", "down", });
	
	set_name("Guard");

	set_level(guard_level);
	set_block_message("The guard standing before the exit blocks your way.");	

}

void guard_reset() {
  int temp;
  set_level(guard_level);
  temp = this_object()->query_max_hp();
  temp *= 30;
  set_max_hp(temp);
  set_hp(query_max_hp());
  set_random_pick(0);
  temp = this_object()->query_max_hp();
  temp /= 10;
  set_regen(temp);
  //set_exp(1);
}

void add_friend(string str) {
	
	if(!str) return;
	
	if(member_array(str,friends) != -1) {
		write(capitalize(str)+" is already in my friends list, sir!\n");
		return;
	}
	friends += ({ str, });
}

void remove_friend(string str) {
	if(!str) return;
	
	if(member_array(str,friends) == -1) {
		write(capitalize(str)+" is not in my friends list, sir!\n");
		return;
	}
	
	friends -= ({ str });
}

void add_block_dir(string str) {

string *dirs;
	
	if(!str) return;
	
	dirs = ROOM->query_dest_dir();
	
	if(member_array(str,allowed_dirs) == -1) {
		write("I cant block "+str+", sir!\n");
		return;
	}
	if(member_array(str,dirs) == -1) {
		write("There are no exit "+str+", sir!\n");
		return;
	}
	if(member_array(str,block_dirs) == -1) {
		write("I'm already blocking "+str+", sir!\n");
		return;
	}
	
	block_dirs += ({ str, });
	add_action("block_move",str);
}

void remove_block_dir(string str) {
	
	if(!str) return;
	
	if(!member_array(str,block_dirs) == -1) {
		write("Im not blocking "+str+", sir!\n");
		return;
	}
	
	block_dirs -= ({ str, });
	remove_action(str);
}

status block_move() {
  int i;

  for(i=0; i<sizeof(friends); i++) {
    if(friends[i] == lower_case(this_player()->query_name())) {
      return 0;
    }
  }

  if(lower_case(this_player()->query_name()) == lower_case(owner)) return 0;

  write(capitalize(this_object()->query_name()) + " blocks your way.\n");
  return 1;
}

status filter_is_player(object ob) {
	
if(interactive(ob) && living(ob))return 1;
return 0;
}


init() {
int i;
object *players;

	::init();
		
	players = all_inventory(environment(this_player()));
	players = filter_array(players,"filter_is_player");
	
	for(i = 0;i<sizeof(players);i++) {
		
		if(member_array(players[i]->query_real_name(),friends) == -1 && guard_aggressive == 1) {
			this_object()->attack_object(players[i]);
			say(short()+" gets mad and attacks "+players[i]->query_name()+"!\n");
		}
	}
				
	if(sizeof(block_dirs) > 0) {
		for(i=0;i<sizeof(block_dirs); i++) {
			add_action("block_move",block_dirs[i]);
		}
	}
}

void catch_tell(string arg) {
  string who, what;

  if(sscanf(arg, "%s attacks %s!", who, what) == 2) {
    if(lower_case(what) == lower_case(owner) || lower_case(what) == "guard") {
      
      if(present("guard 2")) say("Guard says 'Come on pal's, lets slice this wimp!'\n");
      attack_object(present(lower_case(who)));
    }
  }
    
  if(sscanf(arg, "%s starts concentrating on an offensive spell.", who)) {
    if(present(lower_case(who))) {
      
      say("Guard shouts 'Hey, you there! No you dont!'\n");
      attack_object(present(lower_case(who)));
      if(present("guard 2")) say("Guard says 'Come on pal's, lets slice this wimp!'\n");
    }
  }
	
	if(sscanf(arg, "%s arrives",who)) {
		if(present(lower_case(who))) {
		if(member_array(lower_case(who),friends) == -1 && guard_aggressive == 1) {
			say("YOU ARE NOT WELCOME HERE "+capitalize(who)+"!\n");
			attack_object(present(lower_case(who)));
		}
	}
	

}
}