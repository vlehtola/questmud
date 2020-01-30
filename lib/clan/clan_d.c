#define COST 50000
#define DATAFILE "/data/clandata"

mapping clans, scores;
mapping ex_clans;
mapping join;
static string leading_clan;

string query_clan_member(object player,string arg);
string query_clan_leader(object ob, string arg);
string query_clan(object player, string arg);
void end_clan(string name);
int query_cost(string str);
string query_leading_clan();

status display_scores() {
  mixed tmp_str,tmp;
  int i;
  tmp_str = m_indices(scores);
  tmp = m_values(scores);
  write("Current scores of active clans:\n");
  while(i < sizeof(tmp)) {
    write(capitalize(tmp_str[i])+"\t\t"+tmp[i]+"\n");
    i += 1;
  }
  return 1;
}

string query_leading_clan() {
  mixed sc;
  int i, max,x;
  if(leading_clan) return leading_clan;
  sc = m_values(scores);
  if(!sc) return 0;
  for(i=0;i<sizeof(sc);i++) {
    if(max < sc[i]) {
      max = sc[i];
      x = i;
    }
  }
  leading_clan = (string)m_indices(clans)[x];
  return leading_clan;
}

status display_history() {
  mixed tmp_str;
  int i;
  mixed tmp;
  if(ex_clans) {
    tmp_str = m_indices(ex_clans);
    write("Current ex-clans:\n");
    for(i=0;i<sizeof(tmp_str);i++) {
      tmp = ex_clans[tmp_str[i]];
      write(capitalize(tmp_str[i])+"\t\t- End: "+tmp["end date"]+"\n");
    }
    return 1;
  }
  write("There are no ex-clans currently.\n");
}

void modify_clan_score(object killed, object killer) {
  mapping sub, sub2;
  string clan, clan2;
  int i, mod_i;
  /* calculate clan score */
  i = killed->query_level()^2 / killer->query_level()^2;
  if (i < 1) i = 1;

  clan = killed->query_clan();
  sub = clans[clan];
  sub["score"] -= i;
  if(sub["score"] < 0) sub["score"] = 0;
  clans[clan] = sub;
  scores[clan] = sub["score"];

  clan2 = killer->query_clan();
  sub2 = clans[clan2];
  sub2["score"] += i;
  if(sub2["score"] < 0) sub2["score"] = 0;
  clans[clan2] = sub2;
  scores[clan2] = sub2["score"];
  save_object(DATAFILE);
}

void remove_member(object ob) {
  mapping sub;
  string clan, tmp, tmp2;
  clan = ob->query_clan();
  sub = clans[clan];
  if(!sub) return 0;
  tmp = sub["members"];
  ob->set_clan(0);
  if(sscanf(tmp, "%s"+capitalize(ob->query_real_name())+"%s", tmp, tmp2) == 2) {
    tmp = tmp + tmp2;
    while (sscanf(tmp, "%s  %s", tmp,tmp2) == 2)
        { tmp = tmp +" "+ tmp2; }
    if(tmp == " " || tmp == "") tmp = "none";
    sub["members"] = tmp;
  }
  save_object(DATAFILE);
}

status add_member(string clan, object ob) {
  mapping sub;
  string str;
  sub = clans[clan];
  if(!sub) return 0;
  ob->set_clan(clan);
  str = sub["members"];
  if(str == "none") str = "";
  else str = str + " ";
  str = str + ob->query_name();
  sub["members"] = str;
  clans[clan] = sub;
  save_object(DATAFILE);
  return 1;
}

status leave_clan(string arg) {
  this_player()->reset_clan_deaths();
  if(query_clan_member(this_player(),0)) {
    remove_member(this_player());
    write("You left you clan.\n");
    return 1;
  }
  if(query_clan_leader(this_player(),0)) {
    if(!arg || !clans[arg] || arg == this_player()->query_clan()) {
      write("You must give the name of the active clan that has forced you to leave as an argument.\n");
      return 1;
    }
    end_clan(arg);
    write("As you leave, your clan is now history.\n");
    return 1;
  }
  write("You are not in a clan.\n");
  return 1;
}

void end_clan(string name) {
  string clan;
  mapping sub;
  clan = this_player()->query_clan();
  sub = clans[clan];
  sub += (["score": scores[clan] ]);
  clans -= ([ clan ]);
  scores -= ([ clan ]);
  sub += (["end date": ctime(time()) ]);
  ex_clans += ([ clan : sub ]);
  this_player()->set_clan(0);
  save_object(DATAFILE);
}

string query_clan(object player, string arg) {
  string tmp;
  tmp = query_clan_leader(player,arg);
  if(!tmp) tmp = query_clan_member(player,arg);
  return tmp;
}

string query_clan_member(object player,string arg) {
  string str, tmp, tmp2, tmp3, clan;
  mapping sub;
  clan = arg;
  if(!clan) clan = player->query_clan();
  sub = clans[clan];
  if(!sub) return 0;
  str = sub["members"];
  tmp = capitalize(player->query_real_name());
  if(sscanf(str, "%s"+tmp+"%s",tmp2,tmp3) == 2) {
    return clan;
  }
  return 0;
}

string query_clan_leader(object ob, string arg) {
  string clan;
  mapping sub;
  clan = arg;
  if(!clan) clan = ob->query_clan();
  sub = clans[clan];
  if(!sub) return 0;
  if(capitalize(ob->query_real_name()) == sub["leader"]) return clan;
  return 0;
}

int count_members(string clan) {
  mapping sub;
  string tmp,tmp2;
  int i;
  sub = clans[clan];
  if(!sub) return 0;
  tmp = sub["members"];
  while(sscanf(tmp, "%s %s",tmp,tmp2) == 2) {
    if(tmp != "none") i += 1;
  }
  return i;
}

status invite_clan(string name) {
  string clan;
  object ob;
  clan = query_clan_leader(this_player(),0);
  if(!clan) {
    write("You don't lead any clan, so you cannot invite anyone.\n");
    return 1;
  }
  ob = present(name,find_object("room/clan_room"));
  name = capitalize(name);
  if(!ob) {
    write(name+" is not present. Cannot invite.\n");
    return 1;
  }
  if(1+count_members(clan) >= sizeof(m_indices(clans))) {
    write("Cannot have more members when only this few clans active.\n");
    return 1;
  }
  if(join[name]) join -= ([ name ]);
  join += ([ name : clan ]);
  write("You invite "+name+" to your "+capitalize(clan)+" clan.\n");
  tell_object(ob, this_player()->query_name()+" invites you to the clan "+
        capitalize(clan)+".\n");
  return 1;
}

status join_clan() {
  int cost;
  string name, clan;
  if(this_player()->query_wiz() && this_player()->query_wiz() < 4) return 0;
  if(this_player()->query_level() < 50) {
    write("You must be atleast level 50.\n");
    return 1;
  }
  if(query_clan_leader(this_player(),0)) {
    write("You have a clan of your own to worry about.\n");
    return 1;
  }
  if(query_clan_member(this_player(),0)) {
    write("You are already in a clan, leave it first.\n");
    return 1;
  }
  name = this_player()->query_name();
  clan = join[name];
  if(clan) {
    cost = query_cost("join");
    if(cost > this_player()->query_money(3)) {
      write("The joining fee is "+cost+" bronze coins.\n");
      return 1;
    }
    this_player()->reduce_money(cost,3);

    join -= ([ name ]);
    write("You join the clan "+capitalize(clan)+".\n");
    say(name+" joins the clan "+capitalize(clan)+".\n");
    if(!add_member(clan, this_player()))
      write("Joining failed.\n");
    return 1;
  }
  write("You are not invited to any clan.\n");
  return 1;
}

int query_cost(string str) {
  switch(str) {
  case "join" : return COST;
  case "create" : return COST+(50000*(sizeof(m_indices(clans))));
  }
}

status create_clan(string name) {
  mapping sub;
  string str;
  int cost;
  if(this_player()->query_wiz() && this_player()->query_wiz() < 4) return 0;
  if(this_player()->query_level() < 70) {
    write("You must be atleast level 70.\n");
    return 1;
  }
  if(query_clan_leader(this_player(),0)) {
    write("You have a clan of your own to worry about.\n");
    return 1;
  }
  if(query_clan_member(this_player(),0)) {
    write("You are already in a clan, leave it first.\n");
    return 1;
  }
  if(clans[name] || ex_clans[name]) {
    write("You must invite a new name to your clan. That is already in use.\n");
    return 1;
  }
  if(name != lower_case(name)) {
    write("You can use only small letters.\n");
    return 1;
  }
  if(strlen(name) > 8) {
    write("Max name length is 8.\n");
    return 1;
  }
  cost = query_cost("create");
  if(cost > this_player()->query_money(3)) {
    write("The foundation fee is "+cost+" bronze coins.\n");
    return 1;
  }
  this_player()->reduce_money(cost,3);

  sub = ([ ]);
  sub += (["leader":this_player()->query_name()]);
  sub += (["score":0]);
  sub += (["members": "none"]);
  sub += (["date": time()]);
  clans += ([ name : sub ]);
  scores += ([ name : 0 ]);
  this_player()->set_clan(name);
  write("You create a clan called: "+capitalize(name)+"\n");
  save_object(DATAFILE);
  return 1;
}

status info_clan(string name) {
  mapping sub;
  sub = clans[name];
  if(!sub) {
    write("There is no such active clan.\n");
    return 1;
  }
  write("Clan name: "+capitalize(name)+"\n");
  write("   Leader: "+sub["leader"]+"\n");
  write("  Members: "+sub["members"]+"\n");
  write("    Score: "+sub["score"]+"\n");
  write("  Created: "+ctime(sub["date"])+"\n");
  return 1;
}

void clan_eq() {
  if(!this_player()->query_clan()) return;
  if(this_player()->query_clan() == query_leading_clan()) {
    write("You are in the leading clan.\n");
    if(query_clan_leader(this_player(),0) ) {
       move_object(clone_object("/guilds/obj/clan_leader_eq"), this_player());
    }
    else {
       move_object(clone_object("/guilds/obj/clan_member_eq"), this_player());
    }
  }
}

void reset(status x) {
  if(x) return;
  clans = ([ ]);
  ex_clans = ([ ]);
  join = ([ ]);
  scores = ([ ]);
  if(!restore_object(DATAFILE)) {
    save_object(DATAFILE);
  }
}
