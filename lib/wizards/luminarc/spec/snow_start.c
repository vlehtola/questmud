status event_active;

query_name() { return "Snowfight"; }
string query_creator() { return "Luminarc"; }
string query_event_desc() { return
"\The legendary snowball fight.\n"+
"\This event bugs.\n";
}

string query_mortal_desc() { return
"A portal has appeared in the Central Square.\n"+
"You must enter it to participate in the snow\n"+
"fight! Beat your friends in this winrty game!\n";
}

 string query_active() {
         if(event_active) return "Yes";
         return "No";
 }
 void run_event() {
     shout("A mystical portal appears in central square.\n");
     shout("You have still 5min to enter portal and join the fight.\n");
     call_other("/world/city/cs", "add_exit", "portal", "/wizards/luminarc/spec/start");
         event_active = 1;
         call_out("start_event", 300);
 }
  void end_event() {
          event_active = 0;
          call_other("/world/city/cs", "remove_exit", "portal");
  }
 int query_limit() { return 4; }

start_event() {
call_other("/wizards/luminarc/spec/start.c", "start_event");
}
