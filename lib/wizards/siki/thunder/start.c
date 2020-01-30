status event_active;
object ukkonen;
query_name() { return "Thunderstorm"; }
string query_creator() { return "Celtron"; }
string query_event_desc() { return
"\A thunderstorm comes and start zapping people with lightningbolts.\n"+
"\This event duration is aboutjotai0s.\n";
}

string query_mortal_desc() { return
"A deadly thunderstorm has arrived to rain heavenly wrath upon\n"+
"mortal souls. Only the strong can survive...\n";
}

 string query_active() {
         if(event_active) return "Yes";
         return "No";
 }
 void run_event() {
     shout("Dark clouds fill the sky. Suddenly everything goes dark.\n");
     shout("It starts to rain..\n");
         event_active = 1;
         call_out("end_event", 900+random(60));
         call_other("/wizards/siki/thunder/ukkonen.c", "start_thunder");
 }
  void end_event() {
          shout("Suddenly the dark clouds move away from the sky.\n");
          shout("It stops to rain..\n");
          event_active = 0;
          call_other("/wizards/siki/thunder/ukkonen", "end_thunder");
  }
 int query_limit() { return 3; }
