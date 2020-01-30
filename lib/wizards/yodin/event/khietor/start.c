#include "/sys/ansi.h"
status event_active;
object ob;
query_name() { return "Khietor"; }
string query_creator() { return "Neophyte"; }
string query_event_desc() { return
"\An evil dryad arrives to cental square.\n";
}
 string query_active() {
         if(event_active) return "Yes";
         return "No";
 }
 void run_event() {
         shout(""+BOLD+YELLOW_F+"Guards shouts: That evil dryad has arrived in the city."+OFF+"\n");
         shout(""+BOLD+YELLOW_F+"Kill it and you will be awarded."+OFF+"\n");
         ob = clone_object("/wizards/yodin/event/khietor/khietor");
         move_object(ob, "/world/city/cs");
         event_active = 1;
         call_out("end_event", 600);
 }
  void end_event() {
         shout("The dryad shouts: You are all such a pathetic losers!\n");
         find_object("/wizards/yodin/event/khietor/khietor")->self_destruct();
         event_active = 0;
  }
 void winner() {
         int i;
         i = remove_call_out("end_event");
         event_active = 0;
 }


 int query_level() { return 0; }
