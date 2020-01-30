status event_active;
int award;
string winner;
query_name() { return "Hunt the blink dog"; }
string query_creator() { return "Neophyte"; }
string query_event_desc() { return
"\The shepherd have lost his dog while visiting Durangham city.\n\
 The goal of this event is to catch the blink dog which can be\n\
 anywhere in city, where player can go.\n";
}
 string query_active() {
	 if(event_active) return "Yes";
	 return "No";
 }
 void run_event() {
	 call_other("/wizards/neophyte/blink/event.c", "start_event");
	 event_active = 1;
 }
  void end_event() {
 	 call_other("/wizards/neophyte/blink/event.c", "end_event");
 	 event_active = 0;
  }
 int query_level() { return 30; }

void event_win() {
     event_active = 0;
 }

 void winner(string win, int i) {
	 event_active = 0;
	 winner = win;
	 i = award;
	 write_file("/log/huntevent_log", "Winner: "+ winner + " Award: " + i +"\n");
 }