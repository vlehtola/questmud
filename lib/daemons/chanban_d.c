mapping ban;
string *cop;
#define SAVE() save_object("/data/chanban_d");

void reset(status x) {
  if(x) return;
  if(!ban) ban = ([ ]);
  if(!cop) cop = ({ "zapda", });
  if(!restore_object("/data/chanban_d"))
    SAVE();
}

string query_ban(string name,string chan) {
  string *chans;
  name = lower_case(name);
  if(!ban[name]) return 0;
  if(time() >= ban[name][1]) {
    ban = m_delete(ban,name);
    SAVE();
    return 0;
  }
  chans = ban[name];
  if((member_array("all",chans) != -1) || (member_array(chan,chans) != -1))
    return "You are banished from that channel.\n";
  return 0;
}

void add_ban(string name,string chan, int time2) {
  string *chans;

  if (this_player()->query_wiz() < 3) return;
/*
  if(member_array(this_player()->query_real_name(),cop) == -1 && this_player()->query_wiz() < 2) return;
*/

  if(name && (lower_case(name) == "nalle" || lower_case(name) == "celtron"))
	return 0;

  if(ban[name]) {
    if ( ( ((time2*360) + time()) <= ban[name][1] ) || ( time() > ban[name][1] ) ) {
      ban = m_delete(ban,name);
      SAVE();
      return;
    }
    if(member_array(chan,ban[name][0]) != -1) return;
    chans = ({ chan, }) + ban[name][0];
    ban = m_delete(ban,name);
    ban += ([ name:({ chans,(time2*360+time()), }), ]);
  }
  else {
    if(time2 <= 0) return;
    ban += ([ name:({ chan,(time2*360+time()), }), ]);

  }
  log_file("CHANBAN",ctime()+" "+this_player()->query_name()+" banned "+
  name+" for "+time2+"h on "+chan+".\n");
  SAVE();
}

mapping query_bans() { return ban; }
string *query_cop() { return cop; }
