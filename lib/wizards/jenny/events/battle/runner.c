status event_active;
query_name() { return "The battle of the champions"; }
string query_creator() { return "Jenny"; }
string query_event_desc() {
    return "\The master of the wars arrives into the city and asks\n\
everyone to participate a war. War is battle between players in 3x3\n\
rooms and the strongest will win some exp and of course some reputation!\n\
When master arrives people have 10minutes time to sign up and after that\n\
the war begins\n";
}

string query_mortal_desc() {
        return "The master of wars arrives into the city and asks\n"+
        "you to participate to a war. In the war you will fight\n"+
        "against other players, you won't really die if you die\n"+
        "you just get summoned to CS. Winner will get a small amount\n"+
        "of exp and ofcourse some reputation from other players as well\n";
}
 
string query_active() {
if(event_active) return "Yes";
return "No";
}
void run_event() {
    call_other("/wizards/jenny/events/battle/event_ob.c","start_event");
    event_active = 1;
}
void end_event() {
    "/wizards/jenny/events/battle/event_ob"->end_event();
    event_active = 0;
}
int query_limit() { return 2; }
