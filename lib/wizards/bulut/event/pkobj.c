string player;
string players,players1,players2;
string old_players;
string match_player;
string rest_players;
int pos,pos2;
string test1,test2;
object ob;
int exp_award;

id(str) {
return str =="pkobj"; }

short()
{ return "pkobj"; }

long() { write("Just a debug object\n");
}



sign_up(playerlist) {
        players = playerlist;
        }

query_players() {
        return players;
        }

check_players() {
        sscanf(players,"%s %s",test1,test2) ==2;
        if(test2=="") {
        if(find_player(test1)) {  

                shout("Gerdy shouts: " + capitalize(test1) + " is the strongest one!\n");
                write_file("/log/pkevent_log", "Winner: " + capitalize(test1) + "\n");
ob=find_player(test1);
                ob->add_exp(exp_award);
                ob->move_player("X#/world/city/inn");
ob->self_destruct();
                destruct(this_object());
}
        }
}


someone_died(player) {
        players=query_players();
        pos = strstr(players,player,0);
        if(pos) {players1 = extract(players,0,pos -1);}

        if(!pos) {players1 = extract(players,0,strlen(player)  );}
        if(pos) {
        players2 = extract(players, pos + strlen(player) +1 );
        players2 = extract(players2,0,strlen(players2) ); }
        if(!pos) {
        players2 = extract(players, strlen(player) +1 );
        players2 = extract(players2,0,strlen(players2) -1); }
        if ( players1 == " " ) { players1 ==""; }
        if ( players2 == " " ) { players2 ==""; }
        if(pos){
        players = players1 + players2;
        }
        if(!pos){
        players = players2;
        }
        call_out("check_players",2);
}

set_exp_award(i) {
exp_award = i;
}
                                                                           
