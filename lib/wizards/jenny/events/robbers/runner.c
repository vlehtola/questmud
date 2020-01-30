status event_active;
query_name() { return "Gorgola attacks"; }
string query_creator() { return "Jenny"; }
string query_event_desc() {
    return "\The captain of bandits, Gorgola attack the city of Duranghom..\n\
Robbers are of level(10+random(15)) and will attack everyone in sight.\n\
Robbers have 10% chance to steal an equipment from players on each round\n\
when fighting. Robbers wont repop, and event will be on for something like\n\
5 hours because Gorgola is very hard monster to beat. I have tested Gorgola\n\
with Bloodstorm and it is propably 4hours mob or so if mortals have good party.\n\
The event ends when all the Gorgola and all his bandits are killed or the\n\
timelimit has passed\n";
}

string query_mortal_desc() {
        return "Gorgola has terrorized the world for a long time\n"+
        "with his bandits, isn't there anyone who can defeat this\n"+
        "awfull criminal\n";
}
 
string query_active() {
if(event_active) return "Yes";
return "No";
}
void run_event() {
    call_other("/wizards/jenny/events/robbers/event_ob.c","start_event");
    event_active = 1;
}
void end_event() {
    "/wizards/jenny/events/robbers/event_ob"->end_event();
    event_active = 0;
}
int query_limit() { return 2; }

string not_run_with() { return "/wizards/gheldor/events/guglah/runner"; }       
