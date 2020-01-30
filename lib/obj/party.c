/* newpartysys  //Celtron */
/* Added reset and fixed the bug where party
   was left leaderless if the old leader
   quit or left the party --Rag 29.10.03 */

/* If a partymember attacks a monster
   all partymembers attack too --Rag 30.10.03 */

// Added party dice --Rag 30.11.03
// Added 2 query_party_total_exp() och query_party_creation_time() -- 'A' 21.01.2004
// Party report. -Nalle 29.01.2004 (Fixed 18.03.04 -N)
// Party force follow -- Rag 8.3.2004
// Tweaked random_tank function -- Rag 29.3.04
// Increased party name for 3rd rebirthers -- Rag 24.5.04
// Creator can always change the leader -- Rag 3.8.04
// total_exp is actual gained exp/10 to avoid INT_MAX -- Rag 25.9.04

#include "/sys/ansi.h"
#define PARTY "/obj/party"
#define MAX_NAME 15
#define MAX_REBIRTH 25

/* members ([ object player : ({ x, y, }) ]) */
mapping members;
string party_name, *channel_last;
int last_message;
object leader_ob; 	// who leads the party

int total_exp, creation_time, max_player_level;
static object invite_flag;
mapping kills, party_follow;

object creator;

int query_party_total_exp() {
	return total_exp;
}
int query_party_creation_time() {
	return creation_time;
}

void set_creator(object ob) {
  creator = ob;
}

object query_creator() {
  return creator;
}

/**************/
init() {
  add_action("party_pois", "partydest");
}
party_pois() {
  destruct(this_player()->query_party());
}
/**************/

party_help() {
  write("Standard commands:\n");
  write("Party help             ->  Show this screen.\n");
  write("Party create [name]    ->  Creates a party.\n");
  write("Party join             ->  Join to a party when invited.\n");
  write("\n");
  write("Member commands:\n");
  write("Party status           ->  Show current party status.\n");
  write("Party leave            ->  Leave your current party.\n");
  write("Party say [string]     ->  Say something on the party channel.\n");
  write("Party last             ->  Show last party messages.\n");
  write("Party place            ->  Show places in the party.\n");
  write("\n");
  write("Leader commands:\n");
  write("Party name [name]      ->  Rename the party.\n");
  write("Party invite [player]  ->  Invite someone to your party.\n");
  write("Party kick [player]    ->  Kick someone out of your party.\n");
  write("Party shake            ->  Stops members from following.\n");
  write("Party reset            ->  Reset party statistics.\n");
  write("Party dice [sides]     ->  Make all party members throw a die.\n");
  write("Party report           ->  Display your vitals to the party.\n");
  write("Party force follow     ->  Forces members to follow you.\n");
  write("Party place [member] [x] [y]\n\n");
  return 1;
}

party_commands(string str) 
{
  object party, invite_ob, leader_o, ob, *memb;
  string p_name;
  int x,y,i, d;

  if (!str || str == "help") 
    return party_help();

  if (this_player()->query_level() < 1) {
    write("You cannot join a party.\n");
    return 1;  
  }
  party = present("party object", this_player());


  if (sscanf(str, "create %s", p_name) == 1) {

  if (this_player()->query_guest()) 
  { write("Guests cannot create parties.\n"); return 1; }

    if( party || this_player()->query_party() ) {
      write("You are already in party or invited to one.\n");
      return 1;
    }
    if ( (strlen(p_name) > MAX_NAME && this_player()->query_rebirth() < 3) ||
    		 (strlen(p_name) > MAX_REBIRTH && this_player()->query_rebirth() > 2) ) {
        write("Too long party name.\n");
        return 1;
    }
    party = clone_object(PARTY);
    party->set_name(p_name);
    party->set_leader(this_player());
    party->set_creator(this_player());
    this_player()->set_party(party);
    move_object(party, this_player());
    write("You create a party named '" + p_name + "'.\n");
    return 1;
  }

  // allows wizs to view ppl party statuses 
  if (str == "status" || sscanf(str, "status %s", p_name)) {
    party = this_player()->query_party();
    if(!party && !p_name) {
      write("You are not in a party.\n");
      return 1;
    }
    if(p_name && this_player()->query_wiz()) {
      ob = find_player(p_name);
      if(ob) ob = ob->query_party();
      if(!ob) {
        write(capitalize(p_name)+" is not in a party.\n");
        return 1;
      }
      ob->party_status();
      return 1;
    }
    party->party_status();
    return 1;
  }

  if (sscanf(str, "invite %s", p_name) == 1) {
    ob = present(p_name, environment(this_player()));
    if(!party) {
      write("You are not in a party.\n");
      return 1;
    }
    if (!ob) {
        write("No " + capitalize(p_name) + " here.\n");
        return 1;
    }
    if (ob->query_npc() || !living(ob)) {
        write(capitalize(p_name) + " is not a player.\n");
        return 1;
    }
    if (present("party object", ob)) {
        write(capitalize(ob->query_name()) + " is already in a party or is invited to one.\n");
        return 1;
    }
    if(party->query_leader() != this_player()) {
      write("You are not a party leader.\n");
      return 1;
    }
    write("You invite " + ob->query_name() + ".\n");
    party->invite_player(ob);
    return 1;
  }

  if (str == "join") {
    if(!party) {
      write("You have not been invited.\n");
      return 1;
    }
    if(!party->query_invite_flag()) {
	write("You have not been invited.\n");
        return 1;
    }
    ob = party->query_invite_flag()->query_party();
    if(!ob) {
	write("Failed.\n");
	return 1;
    }
    ob->add_party_member(this_player());
    write("You join the party.\n");
    destruct(party);
    return 1;
  }

  if (!this_player()->query_party()) {
    write("You are not in party.\n");    
    return 1;    
  }     
  if( str == "shake") {
    if (!party) {
      write("You are not the leader.\n");
      return 1;
    }
    party->party_say("shakes the party. All members stop following.",this_player()->query_name(), 1);
    party->reset_party_follow();
    return 1;
  }

  if (str == "place") {
    this_player()->query_party()->write_place();
    return 1;
  }

  if (sscanf(str, "place %s %d %d", p_name, x, y) == 3) {
    if (!party) {
      write("You are not the leader.\n");
      return 1;
    }
    ob = find_player(p_name);
    if(!ob || !party->is_member(ob)) {
      write("No such a member.\n");
      return 1;
    }
    if (party->change_place(ob,x,y)) {
      write("Placing "+capitalize(p_name)+" in coordinates "+x+","+y+".\n");
    } else {
      write("The place is already occupied.\n");
    }
    return 1;
  }

  if (str == "follow") {
    if(party) {
	write("You cannot follow yourself.\n");
	return 1;
    }
    this_player()->query_party()->swap_party_follow();
    return 1;
  }
  if (sscanf(str, "kick %s", p_name)) {
    if(!party) {
       write("You are not the leader.\n");
       return 1;
    }
    invite_ob = find_player(p_name);
    if(!invite_ob || !party->is_member(invite_ob)) {
      write("No such a member.\n");
      return 1;
    }
    party->remove_party_member(invite_ob);
    return 1;
  }
  if (str == "leave") {
    party = this_player()->query_party();
    if(party) {
      party->remove_party_member(this_player());
      write("You left the party.\n");
    }
    return 1;
  }
  if (sscanf(str, "leader %s", p_name) == 1) {
    if(!party && this_player()->query_party()->query_creator() != this_player() ) {
      write("You are not the leader.\n");
      return 1;
    }
    //invite_ob = present(p_name, environment(this_player() ));
    //Changed by Rag 3.8.04
    invite_ob = find_player(p_name);
    if(!invite_ob || !this_player()->query_party()->is_member(invite_ob)) {
      write("No such a member.\n");
      return 1;
    }
    this_player()->query_party()->change_leader(invite_ob);
    return 1;
  }
  if (str == "kills") {
    this_player()->query_party()->show_party_kills();
    return 1;
  }
  if (sscanf(str, "say %s", p_name) == 1) {
    this_player()->query_party()->party_say(p_name, this_player()->query_name());
    return 1;
  }
  if (str == "last") {
    this_player()->query_party()->show_party_messages();
    return 1;
  }
  if (sscanf(str, "name %s", str) == 1) {
    if(!party) {
       write("You are not the leader.\n");
       return 1;
    }
    if ( (strlen(str) > MAX_NAME && this_player()->query_rebirth() < 3) ||
    		 (strlen(str) > MAX_REBIRTH && this_player()->query_rebirth() > 2) ) {
        write("Too long party name.\n");
        return 1;
    }
    write("You rename your party to '"+str+"'.\n");
    party->set_name(str);
    return 1;
  }

  if (str == "reset") {
    if(!party) {
       write("You are not the leader.\n");
       return 1;
    }
    party->party_reset();
    return 1;
  }

  if (sscanf(str, "dice %d", d) == 1) {
    if(!party) {
       write("You are not the leader.\n");
       return 1;
    }
    party->party_dice(d);
    return 1;
  }

  // Nalle was here 29.01.04
  if (str == "report" || str == "report stats") 
  {
    // Rag was here, the object 'party' is present only in the leader 8.3.2004
    this_player()->query_party()->party_report( (str == "report stats") );
    return 1;
  }

  if ( str == "force follow" ) {
    if ( !party ) {
      write("You are not the leader.\n");
      return 1;
    }
    party->force_follow();
    return 1;
  }

  write("Try 'party help'\n");
  return 1;
}

//The whole party attacks an innocent monster!
int party_attack(object target, object attacker, int not_attack) {
	int i;
	object *memb;
	memb = m_indices(members);
	for(i=0;i<sizeof(memb);i++) {
		//Something bugs here or there
		//memb[i]->query_party()->check_row(memb[i]);
		if(memb[i] != attacker && environment(memb[i]) == environment(attacker)) {
		  memb[i]->attack_object(target, not_attack);
		}
	}
	return 1;
}

//Check if there are empty places in front of ob
//This function is not called because it might bug
int check_row(object ob) {
	int x,y,i,j, free_place;
	object p_ob, m_ob;
	string str;
	x = members[ob][0];
	y = members[ob][1];
	p_ob = ob->query_party();
	if(y == 1) return 1;
	for(i=1;i<y;i++) {
		if(!p_ob->member_in_place(x,i)) {
			free_place = i;
			for(j=free_place;j<y;j++) {
				m_ob = p_ob->member_in_place(x,j+1);
				if(m_ob) {
					p_ob->change_place(m_ob,x,j);
					switch(j) {
					case 1: str = "first"; break;
					case 2: str = "second"; break;
					case 3: str = "third"; break;
					case 4: str = "fourth"; break; //This shouldn't be possible
					}
					p_ob->party_say("is now in the "+str +" row.",ob->query_name(),1);
				}
			}
		return 1;
		}
	}
	return 1;
}


object query_invite_flag() { return invite_flag; }
void set_name(string name) { party_name = name; }
object query_leader() { return leader_ob; }

status first_in_row(object player) {
  if(!members[player]) return 0;
  if(members[player][1] == 1) return 1;
  return 0;
}

void reset_party_follow() {
  party_follow = ([ ]);
}

void swap_party_follow() {
  object leader_o;
    leader_o = this_player()->query_party()->query_leader();
    if(!present(leader_o, environment(this_player()) )) {
      write("Your leader is not here.\n");
      return;
    }
    if (!party_follow[this_player()->query_name()]) {
      party_follow += ([ this_player()->query_name() : 1 ]);
      write("You start following "+leader_o->query_name() + ".\n");
      tell_object(leader_o, this_player()->query_name() +" starts following you.\n");
      return;
    } else {
      party_follow -= ([ this_player()->query_name() ]);
      write("You stop following " + leader_o->query_name() + ".\n");
      tell_object(leader_o, this_player()->query_name()+" stops following you.\n");
    }
}

void force_follow() {
  object leader_ob;
  object *member_ob;
  int i;

  leader_ob = query_leader();
  member_ob = m_indices(members);

  for ( i = 0; i < sizeof(member_ob); i++ )
  {
    if ( !party_follow[member_ob[i]->query_name()] &&
         member_ob[i] != leader_ob &&
         environment(member_ob[i]) == environment(leader_ob) )
    {
      party_follow += ([ member_ob[i]->query_name() : 1 ]);
      tell_object(member_ob[i],"You start following "+leader_ob->query_name() + ".\n");
      tell_object(leader_ob, member_ob[i]->query_name() +" starts following you.\n");
    }
  }
}

status valid_for_exp(object player);

party_status() {
  int x,y,stop, xp_pros;
  string tmp,tmp2,tmp3,tmp4,tmp5,tmp6, xp_tmp;
  int party_age, age_in_minutes, member_count, i;
  object *member_ob;

  party_age = (time()-creation_time);
  age_in_minutes = party_age / 60;
  if(!age_in_minutes) age_in_minutes++;

  member_count = m_sizeof(members);

  tmp = "+--------------------------------------------------------------------------+";
  tmp2 = "                                                                           ";
  write(tmp+"\n");
  if(this_player()->query_wiz()) {
    tmp3 = "| <"+party_name+"> (Age: "+call_other("/obj/player", "stime",party_age)+")"+
	" Total exp: "+(total_exp/100)+"k Xp/min: "+(total_exp/age_in_minutes/100)+
	"k Xp/min/mbr: "+(total_exp/age_in_minutes/member_count/100)+"k";
  } else {
    tmp3 = "| Party name: "+party_name+" (Age: "+call_other("/obj/player", "stime",party_age)+")"+
	" Total experience: "+(total_exp/100)+"k ("+member_count+" member(s))";
  }

  write(tmp3 + extract(tmp2,0,strlen(tmp2)-strlen(tmp3))+"|\n");
  write(tmp+"\n");

  member_ob = m_indices(members);
  for(i=0; i < sizeof(member_ob); i++) {
    if(member_ob[i]) {
      tmp4 = "[mbr] ";
      if (member_ob[i] == leader_ob) { tmp4 = "{ldr} "; }
      else if (party_follow[member_ob[i]->query_name()] ) { tmp4 = "[fol] "; }
      if(member_ob[i]->query_link_dead()) { tmp4 = "[ld]  "; }
      tmp5 = member_ob[i]->query_name();
      /* liian pitk�t nimet */
      if(strlen(tmp5) < 10) {
        tmp5 = tmp5+extract(tmp2,0,9-strlen(tmp5));
      }
      tmp6 = "["+member_ob[i]->query_level()+"]";
      if(strlen(tmp6) < 6) tmp6 = tmp6+extract(tmp2,0,5-strlen(tmp6));
      xp_pros = member_ob[i]->query_level()*100/query_total_level();
      if(xp_pros > 100) xp_pros = 100;

      xp_tmp = "~"+to_string(xp_pros)+"%";
      if(!valid_for_exp(member_ob[i])) {
	xp_tmp = "None";
      }

      tmp3 = tmp4+tmp6+tmp5+"Hp:"+member_ob[i]->get_color("hp")+"("+
	member_ob[i]->query_max_hp()+") Sp:"+member_ob[i]->get_color("sp")+
	"("+member_ob[i]->query_max_sp()+") Ep:"+member_ob[i]->get_color("ep")+
	"("+member_ob[i]->query_max_ep()+") "+ xp_tmp;

      y = members[member_ob[i]][1];
      if(y == 1) tmp5 = "front  ";
      if(y == 2) tmp5 = "middle ";
      if(y == 3) tmp5 = "back   ";
      //if(y == 4) tmp5 = "back   ";
      tmp3 = "| "+tmp5+tmp3;
      if(strlen(tmp3) < strlen(tmp2)) {
        tmp3 = tmp3 + extract(tmp2,0,strlen(tmp2)-strlen(tmp3))+"|";
      }
      write(tmp3+"\n");
    }
  }
  write(tmp+"\n");
  return 1;
}

query_party_follow() { return party_follow; }

id(str) {
    return str == "party object";
}

drop() {
    return 1;
}

void reset(status arg) {
  if (arg) { return; }
  if (leader_ob == 0) {
   leader_ob = this_player();
   this_player()->set_leader_ob(this_player());
   members = ([ ]);
   members += ([ leader_ob: ({1,1,}) ]);
   kills = ([ ]);
   party_follow = ([ ]);
   creation_time = time();
  }
  channel_last = allocate(20);
}

void add_party_kill(string killed, int killed_exp) {
  string party_age, line, spaces;
  int i;
  object *member_ob;
  spaces = "                                          ";
  party_age = "/obj/player"->stime(time() - creation_time);
  line = force_string_length(party_age, 15) + force_string_length(killed, 25) + " "
		+ force_string_length(killed_exp+"xp", 15);
  kills += ([ (int) m_sizeof(kills) : (string) line ]);

  // try set best kills for partymembers

  member_ob = m_indices(members);
  if(sizeof(member_ob) == 1) {
    member_ob[0]->set_best_kill(killed, killed_exp);
    return;
  }
  for(i=0; i < sizeof(member_ob); i++) {
    member_ob[i]->set_best_kill(killed, killed_exp, sizeof(member_ob) );
  }

}

status show_party_kills() {
  int i, i_start;
  if(!m_sizeof(kills)) {
    write("Nothing killed yet..\n");
    return 1;
  }
  write("Displaying recently killed monsters:\n");
  i_start = m_sizeof(kills)-1;
  for(i = i_start; i > i_start - 15 && i >= 0; i--) {
    write(kills[i]+"\n");
  }
  return 1;
}

void set_party_name(string p_name) { party_name = p_name; }
string query_party_name() { return party_name; }
mapping query_members() { return members; }
void find_max_player_level();


// turha funcca ?
void send_party_message(string msg) {
  int i;
  object *member_ob;
  member_ob = m_indices(members);
  for(i=0; i < sizeof(member_ob); i++) {
    tell_object(member_ob[i], msg);
  }
}

void party_say(string msg, string player, status reversed) {
  int i;
  object *member_ob;
  member_ob = m_indices(members);
  for(i=0; i < sizeof(member_ob); i++) {
    if(reversed) {
      tell_object(member_ob[i], CYAN_F+"[party]: "+OFF+player+" "+msg+"\n");
    } else {
      tell_object(member_ob[i], player+CYAN_F+" [party]: "+OFF+msg+"\n");
    }
  }

  last_message -= 1;
  if(last_message < 0) last_message = sizeof(channel_last)-1;
  channel_last[last_message] = ctime(time())[11..15]+" "+player+" [party]: "+msg;
}

void show_party_messages() {
  int i;
  for(i=last_message-1; i >= 0; i--) {
    if(channel_last[i])
	write(channel_last[i]+"\n");
  }
  for(i= sizeof(channel_last)-1; i > last_message-1; i--) {    
    if(channel_last[i])
	write(channel_last[i]+"\n");
  }
}

void invite_start(object player, object leader) {
  invite_flag = leader;
  call_out("invite_stop", 30, player, leader);
}

void invite_stop(object player, object leader) {
  if(player) tell_object(player, "You didn't take the offer.\n");
  if(leader) tell_object(leader, "Your invitation was turned down.\n");
  destruct(this_object());
}

status invite_player(object player) {
  object party;
  if(!living(player) || player->query_npc()) {
    write(player->query_name()+" is not a player.\n");
    return 1;
  }
  if(player->query_party()) {
    write(player->query_name() + " already is in a party.\n");
    return 1;
  }
  tell_object(player, leader_ob->query_name() + " invites you to a party called '" + party_name + "'\n" + 
                "Type 'party join' in 30 seconds to join.\n");
  party = clone_object(PARTY);
  party->invite_start(player, leader_ob);
  move_object(party, player);
  return 1;
}

// returns coords of the first free place
int *get_free_place() {
  mixed *places;
  int x, y, i, place_flag;
  places = m_values(members);
  for(x=1; x <= 3; x++) {
    for(y=1; y <= 3; y++) {
      for(i=0; i < sizeof(places); i++) {
        if(places[i][0] == x && places[i][1] == y) place_flag = 1;
      }
      // vapaa paikka on loytynyt!!
      if(!place_flag) return ({ x, y, });
      place_flag = 0;
    }
  }
  return 0;
}

// return 0 if party is full, 1 if joined
status add_party_member(object player) {
  int *place;
  if(m_sizeof(members) >= 9) return 0;
  place = get_free_place();
  if(!place) {
    write("Party place error. No free places!\n");
    return 0;
  }
  members += ([ player : place ]);
  party_say("is now a member of the party.", player->query_name(), 1);
  player->set_party(this_object());
  if (!party_follow[player->query_name()]) {
      party_follow += ([ player->query_name() : 1 ]);
  }
  find_max_player_level();
  return 1;
}

void change_leader(object new_leader) {
  int i;
  object *member_ob;
  member_ob = m_indices(members);
  for(i=0; i < sizeof(member_ob); i++) {
    if(member_ob[i] == new_leader) {
      leader_ob = new_leader;
      move_object(this_object(), new_leader);
      party_say("is the new leader of the party.",leader_ob->query_name(),1);
    }
  }
}

void change_leader_to_next() {
  int i;
  object *member_ob;
  member_ob = m_indices(members);

  for(i=0; i < sizeof(member_ob); i++) {
    if(member_ob[i] && !member_ob[i]->query_link_dead() && member_ob[i] != leader_ob) {
      change_leader(member_ob[i]);
      return;
    }
  }
}

void party_move(object last_room, string dir) {
  int i;
  object *member_ob;
  member_ob = m_indices(members);
  for(i=0; i < sizeof(member_ob); i++) {
    if(environment(member_ob[i]) == last_room && member_ob[i] != leader_ob && party_follow[member_ob[i]->query_name()] ) {
    // leader commands thou.. doesn't work on wizs (simul_efun)
      command(dir, member_ob[i]);
    } else if (member_ob[i] != leader_ob && party_follow[member_ob[i]->query_name()] ) {
      tell_object(member_ob[i], "Your leader moves without you!\n");
      party_follow -= ([ member_ob[i]->query_name() ]);
    }
  }
}

// tuned by C. if playerlevels have big differences, total xp is 100%
int query_total_level() {
  int i, total_level, count, min_lv, max_lv, lv;
  object *member_ob;
  member_ob = m_indices(members);
  min_lv = 1000; // just to be sure
  for(i=0; i < sizeof(member_ob); i++) {
    if( !member_ob[i]->query_link_dead() && !member_ob[i]->query_dead() ) {
	lv = member_ob[i]->query_level();
	if(lv < min_lv) min_lv = lv;
	if(lv > max_lv) max_lv = lv;
	total_level += lv;
	count += 1;
    }
  }
  /* more xp to party (-20% total level max) //Celtron */
  if(count>1) {
    lv = max_lv - min_lv;
    lv = (20 - lv/4);
    if(lv < 0) lv = 0; // cap the xp loss. min total perc = 100%
    total_level -= total_level*lv/100;
  }
  if(total_level < 1) total_level = 1; // evade division per zero
  return total_level;
}

void find_max_player_level() {
  int i, plvl;
  object *member_ob;
  member_ob = m_indices(members);
  for(i=0; i < sizeof(member_ob); i++) {
    plvl = member_ob[i]->query_level();
    if(plvl > max_player_level)
      max_player_level = plvl;
  }
}

// checks if a player can have xp in a party, so that he is not being pumped by highbies
// 20051026 C

status valid_for_exp(object player) {
  if(!max_player_level) find_max_player_level();
  // does not apply for level 60 players or above
  if(player->query_level() > 59) { return 1; }
  if(player->query_level()*2+20 > max_player_level) {
    return 1;
  }
  return 0;
}

void distribute_exp(int exp, string short_d, int monster_level) {
  int i, e, total_level;
  object *member_ob;
  member_ob = m_indices(members);
  // add exp to party totals
  //Kludge-fix (blame Nalle!) -- Rag 25.9.04
  total_exp += exp/10;

  total_level = query_total_level();
  if (!total_level) { total_level = 1; }

  for(i=0; i < sizeof(member_ob); i++) {
    if(!member_ob[i]->query_link_dead() && !member_ob[i]->query_dead()) {
      e = (exp / total_level) * member_ob[i]->query_level();
      if(valid_for_exp(member_ob[i]))
        member_ob[i]->add_party_exp(e, short_d, monster_level);
    }
  }
  // add to party kills
  add_party_kill(short_d, exp);
}      

status is_member(object player) {
  int i;
  object *member_ob;
  member_ob = m_indices(members);
  for(i=0; i < sizeof(member_ob); i++) {
    if(member_ob[i] == player)
      return 1;
  }
  return 0;
}

void remove_party_member(object player) {
  int i;
  object *member_ob, party;
  member_ob = m_indices(members);
  for(i=0; i < sizeof(member_ob); i++) {
    if( member_ob[i] == player ) {
      party_say("left the party.", player->query_name(), 1);
      members -= ([ player ]);
      if(player->query_party()->query_leader() == player) {
	player->query_party()->change_leader_to_next();
      }
      player->set_party();
    }
  }
  if(m_sizeof(members) == 0) {
    write("No active party members. Party destroyed.\n");
    destruct(this_object());
  }
  find_max_player_level();
}

object member_in_place(int x, int y) {
  int i;
  object *member_ob;
  member_ob = m_indices(members);
  for(i=0; i < sizeof(member_ob); i++) {
    if(members[member_ob[i]][0] == x && members[member_ob[i]][1] == y)
       return member_ob[i];
  }  
  return 0;
}

status change_place(object player, int x, int y) {
  int i;
  if (!is_member(player)) {
    write("No such a member.\n");
    return 0;
  }
  if (x < 1 || y < 1 || x > 3 || y > 3) {
    write("Illegal coordinates.\n");
    return 0;
  }
  if (member_in_place(x,y)) {
    write("There is already someone in that place.\n");
    return 0;
  }
  members += ([ player : ({x,y,}) ]);
  return 1;
}


/* arvontalaulu raikaa, kuka ottaa klamathii isolta pahalta monsterilta */
object random_tank(object defender) {
  int x,y,i,tank_n;
  object *tanks, tank, current;
  tanks = allocate(3);
  tank_n = 0;
  // who can potentially take damage
  for(x=1; x < 4; x++) {
    for(y=1; y < 4; y++) {
      current = member_in_place(x, y);
      if (current && environment(current) == environment(defender) && !current->query_dead()) {
        tanks[x-1] = current;
        tank_n++;
        y = 4;
      }
    }
  }
  // bravery skill
  for(i=0; i < sizeof(tanks) && !tank; i++) {
    if(tanks[i] && random(250) < tanks[i]->query_bravery()) {
      tell_object(tanks[i], "You bravely draw the attack to yourself!\n");
      tank = tanks[i];
    }
  }

  // random tank, changed from random(3) to randon(tank_n) -- Rag
  if(!tank) tank = tanks[ random(tank_n) ];

  for(i=0; !tank && i < sizeof(tanks); i++) {
    if(tanks[i]) tank = tanks[i];
  }
  if (!tank) { log_file("TANK_ERROR", ctime(time()) + " "+this_player()->query_name()+" No tank from check! (no error possible)\n"); }
  return tank;
}

void write_place() {
  int x,y;
  string str, line;
  object current;
  write("+------------------------------------------------------------+\n");
  for(y=1; y < 4; y++) {
    line = "|";
    for(x=1; x < 4; x++) {
      current = member_in_place(x,y);
      if(current) {
	  str = "("+x+","+y+") "+current->query_name();
          line += force_string_length(str, 20);
      } else {
          str = "("+x+","+y+") <empty>";
          line += force_string_length(str, 20);
      }
    }
    line += "|\n";
    write(line);
  }
  write("+------------------------------------------------------------+\n");
}

party_reset() {
    write("Resetting party statistics...\n");
    creation_time = time();
    total_exp = 0;
    kills = ([ ]);
    return 1;
}

int party_report(int stats)
{
 string result;

 call_other("/cmds/std/_report", "???", 0); // Loadbug fixed. -N

 result = find_object("/cmds/std/_report")->give_string(this_player(), stats );
 party_say("reports '"+ result +"'.", this_player()->query_name(), 1);

 return 1;
}

party_dice(d) {
	object *membs;
	mapping dices;
	int i, j, tmp, biggest;
	string name, biggest_name;

	//Generic blahblah
	if(!d) {
		write("Usage: party dice [number]\n");
		return 1;
	}
	if (d < 2 || d > 1000) {
		write("Number can not be less than 2 or greater than 1000.\n");
		return 1;
	}
	party_say("calls for a party dice with a "+d+"-sided die.", this_player()->query_name(), 1);
	membs = m_indices(members);
	dices = ([]);

	//The dice
	for(i=0;i<sizeof(membs);i++) {
		tmp = random(d) + 1;
		dices += ([ membs[i]->query_name(): tmp ]);
	}

	//Sorting the results
	for(j=0;j<sizeof(membs);j++) {
	 biggest = -1;
	 biggest_name = "";
	 for(i=0;i<sizeof(membs);i++) {
		name = membs[i]->query_name();
		if( dices[name] > biggest) {
			biggest = dices[name];
			biggest_name = name;
		}
	 }
	 dices -= ([biggest_name]);
	 party_say("got "+biggest+".",biggest_name, 1);
	}
	return 1;
}

/* 
#################################################

DONE SO FAR

#################################################
*/



