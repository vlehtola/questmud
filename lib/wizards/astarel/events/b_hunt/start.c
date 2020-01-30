// Bunny - hunt

include "/wizards/astarel/events/b_hunt/defines.h"

// vars

int run;


// event-required funcs:

query_name() { return "Bunny hunt"; }

string query_creator() { return "Astarel"; }

string query_event_desc() { return	"Morts tries to catch as many bunnies as they can from bunnyholes\n"+
					"that appears in the outworld map.\n";
	}
				
string query_mortal_desc() { return	"Try to catch as many bunnies as you can!\n";
	}	

int query_limit() { return 1; }

string query_active() {
	if(run) return "yes";
	return "no";
}


void run_event() {
	run = 1;
	BUNNY_D->start_bunny_event();
	return

}

void end_event() {
	run = 0;
	BUNNY_D->stop_bunny_event();
	return
}
