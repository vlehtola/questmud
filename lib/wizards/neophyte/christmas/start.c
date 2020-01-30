status event_active;
object ob;
query_name() { return "Christmas"; }
string query_creator() { return "Neophyte"; }
string query_event_desc() { return
"\An santa claus arrives to duranghom cental square to giving out free presents.\n";
}
 string query_active() {
	 if(event_active) return "Yes";
	 return "No";
 }
 void run_event() {
	 shout("Santa claus arrives cental square.\n");
	 ob = clone_object("/wizards/neophyte/christmas/santa");
	 move_object(ob, "/world/city/cs");
	 event_active = 1;
 }
  void end_event() {
	 shout("Santa claus leaves from the city, wishing you all merry christmas.\n");
	 find_object("/wizards/neophyte/christmas/santa")->self_destruct();
 	 event_active = 0;
  }

 int query_level() { return 0; }

