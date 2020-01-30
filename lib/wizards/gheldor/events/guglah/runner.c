status event_active;
query_name() { return "Guglah-Invasion"; }
string query_creator() { return "Gheldor"; }
string query_event_desc() {
    return "\The guglah race are trying to invade the City.\n\
They are of level(1+random(5)) and trying to kill everyone in sight.\n\
The event ends when all the guglahs are killed or the timelimit has passed,\n\
whichever comes first...\n";
}

string query_mortal_desc() {
        return "The guglah race are trying to invade the City.\n"+
        "They are known to be very aggressive. Therefor you must\n"+
        "do your best to defeat this threat.\n";
}

string query_active() {
if(event_active) return "Yes";
return "No";
}
void run_event() {
    call_other("/wizards/gheldor/events/guglah/event_ob.c","start_event");
    event_active = 1;
}
void end_event() {
    "/wizards/gheldor/events/guglah/event_ob"->end_event();
    event_active = 0;
}
int query_limit() { return 2; }

string not_run_with() { return "/wizards/jenny/events/robbers/runner"; }
