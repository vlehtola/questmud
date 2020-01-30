status event_active;
object ob;
query_name() { return "Thief"; }
string query_creator() { return "Neophyte"; }
string query_event_desc() { return
"\An agile thief arrives Duranghom to pillage and rob citizens.\n";
}
 string query_active() {
	 if(event_active) return "Yes";
	 return "No";
 }
 void run_event() {
	 shout("An agile thief arrives Duranghom to pillage and rob citizens.\n");
	 ob = clone_object("/wizards/neophyte/thief/thief");
	 move_object(ob, "/world/city/inn");
	 event_active = 1;
	 call_out("end_event", 900);
 }
  void end_event() {
	 shout("Thief shouts: I am rich and out of here!\n");
	 destruct(ob);
 	 event_active = 0;
  }
 void winner() {
	 int i;
	 i = remove_call_out("end_event");
	 event_active = 0;
 }


 int query_level() { return 100; }

