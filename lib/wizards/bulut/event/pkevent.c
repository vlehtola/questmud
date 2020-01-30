object ob;
object shadow;
int time;
int from;
int to;
int len;
int playerslen;
int i;
int exp_award;

string players;
string next_player;
object player;
short() { return "A small clock";}

init() {
add_action("drop","drop");
add_action("query_players","query_players");
add_action("query_next","query_next");
if(find_call_out("event_start") == -1 ) {
                call_out("event_start", 300);
shout("Gerdy shouts: You have 5 minutes to sign up!\n");
call_out("event3min", 120);
call_out("event2min", 180);
call_out("event1min", 240);
call_out("event30sec", 270);
call_out("event10sec", 290);
        }

if (!players) {
        exp_award = 1000000;
 players = lower_case(this_player()->query_name() +" "); return 1;}

players=players+lower_case(this_player()->query_name()+" ");
exp_award = exp_award + 1000000;
if (exp_award > 10000000) {
exp_award = 10000000;
}
}

event3min() {
shout("Gerdy shouts: You have 3 minutes to sign up!\n");
}
event2min() {
shout("Gerdy shouts: You have 2 minutes to sign up!\n");
}
event1min() {
shout("Gerdy shouts: You have 1 minute to sign up!\n");
}
event30sec() {
shout("Gerdy shouts: You have 30 seconds to sign up!\n");
}
event10sec() {
shout("Gerdy shouts: You have 10 seconds to sign up!\n");
}

query_players() {
        return players;
        }


query_time() {
        return find_call_out("event_start");
        }

query_next() {
        next_player == query_players();
        players == query_players();

        while(strlen(players) > 1 ) {
                sscanf(players,"%s %s", next_player, players) == 2;
                write(next_player +"\n");
                }                        
}

event_start() {
        find_object("/wizards/bulut/event/pkobj")->sign_up(players);
find_object("/wizards/bulut/event/pkobj")->set_exp_award(exp_award);
        write_file("/log/pkevent_log", "Joined: " + players + "\n");
write_file("/log/pkevent_log", "Exp_Award: " + exp_award + "\n");
tell_room(environment(this_object()),"Gerdy shouts:Let the fight BEGIN! Winner will get " + exp_award + " exp!\n");
shout("Gerdy shouts: Let the fight begin! Winner will get " + exp_award + " exp!\n");
        tell_room(environment(this_object()),"Suddenly your surroundings change!\n");
        next_player == query_players();
        players == query_players();

        while(strlen(players) > 1) {
                sscanf(players,"%s %s", next_player, players) == 2;
                player=find_player(next_player);
                ob = clone_object("/wizards/bulut/event/pkeq");
                shadow = clone_object("/wizards/bulut/event/shadow");
                shadow->start(player);
                move_object(ob,player);
                move_object(player,"/wizards/bulut/event/room1");
                }

find_object("wizards/bulut/event/pkmaster")->self_destruct();
find_object("wizards/bulut/event/sign")->self_destruct();
        destruct(this_object());
return 1;
        }

id(str) {
        return str == "clock";
        }


long(str) {
        write("Clock shows: " + query_time() + "\n");
        write("Following people have signed up: " + query_players() + ".\n");
        }

drop() {
        write("Littering is bad, mmkay?.\n");
        return 1;
        }

self_destruct() {
while(ob = find_object("/wizards/bulut/event/pkevent")) {
 destruct(ob);}
destruct(this_object());
}                                                                                            
