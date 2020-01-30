
#include "/wizards/astarel/events/b_hunt/defines.h"


// VARS

mapping mapp;  // ([ name : bunny1 ; bunny2 ; bunny3 ; bunny4 ; bunny 5, ])

string *names, *bunny_loc;
string coord_x,coord_y;

object belg_ob;

// PROTOS

void start_bunny_event();
void add_bunnyhunter(string str);
void add_bunny_score(string str, int i);
void clone_start_bunnies(int i);
void get_map_coords();

// RESETS


void reset_all() {
	mapp = ([ ]);
	names = ({ });
	bunny_loc = ({ });
}

void start_bunny_event() {

	mapp = ([ ]);
	names = ({ });
	bunny_loc = ({ });
	
	
	
	//belg_ob = clone_object(BELG);
	//move_object(belg_ob, BELG_LOCATION);
	//clone_start_bunnies(BUNNY_MAX);
	tell_room(BELG_LOCATION, "BUNNYHUNT STARTS!\n");
	
	return;
}

void add_bunnyhunter(string str) {
	
	string name;
		
	if(!str) return;
	
	name = str;
	
	if(member_array(name, names) != -1) {
		tell_object(find_player(name), "You have already joined this event!\n");
		return;
	}
	
	names += ({ name, });
	
	mapp += ([ name : 0 ; 0 ; 0 ; 0 ; 0, ]);
		
	tell_object(find_player(name), "You joined the event!\n");
	
return;
}

void add_bunny_score(string str, int i) {

int tmp;

tell_object(find_player("astarel"), "str: "+str+", i: "+i+" \n");

tmp = mapp[str,i];

tmp = tmp + 1;
if(i == 0)mapp[str,0] = tmp;
else mapp[str,i] = tmp;

tell_object(find_player(str), "You just scored "+i+" \n");

return;
}

// Just to check things
mapping query_hunters() {
	return mapp;
}

void get_map_coords() {

string tmp;

	coord_x = random(200);
	coord_y = random(200);

	tmp = OMAP->get_map_char(coord_x,coord_y);
	
	// Pit��h�n sinne p��st�
	if(OMAP->check_no_walk(tmp)) {
		get_map_coords();
	}
	
	// Bunnyholeja ei teille, eik� special paikkoihin
	if(tmp == "+" || tmp == "-" || tmp == "/" || tmp == "|" || tmp == "\\" || tmp == "?" || tmp == "#" || tmp == "=") {
		get_map_coords();
	}
		
}


void create_start_bunnies(int i) {

string tmp;
int amount;

amount = i;

// Lets clone the bunnies!
for(i = 0; i < amount ; i++) {

// lets get the coordinates	
get_map_coords();




