status event_active;
object healer;
query_name() { return "Healer"; }
string query_creator() { return "Neophyte"; }
string query_event_desc() { return
"\An travelling healer arrives Duranghom to heal all players.\n"+
"\This event duration is about 180s.\n";
}
 string query_active() {
	 if(event_active) return "Yes";
	 return "No";
 }
 void run_event() {
	 healer = clone_object("/wizards/neophyte/healer/healer");
	 move_object(healer, "/world/city/cs");
	 shout("The healer shouts: I have come to Duranghom to heal you all.\n");
	 tell_room("/world/city/cs", "Healer arrives from somewhere.\n");
	 event_active = 1;
	 call_out("end_event", 180);
 }
  void end_event() {
	  if(!healer) {
 	      event_active = 0;
 	      return;
	  }
	  shout("The travelling healer leaves from Duranghom.\n");
	  event_active = 0;
	  destruct(healer);
  }
 int query_level() { return 10; }