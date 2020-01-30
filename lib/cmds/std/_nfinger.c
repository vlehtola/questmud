
#define LEADER_D  "/daemons/leader_d"
#define GUILDRANK_D "/daemons/guildrank_d"

cmd_nfinger(string nam) {
  object ob;
  int online, since, i, m;
  string pronoun, type, tmp, married;

  if (!this_player()->check_condis()) { return 1; }
  if (!nam || sscanf(nam, "%s %s",nam,tmp) == 2) {
      write("Usage: finger <player name>\n");
      return 1;
  }
  ob = find_player(nam);
  online = 1;
  if (!ob) {
    ob = clone_object("obj/player.c");
    if (!ob->restore_player(nam) || nam == "logon") {
      write("No such player. ('"+nam+"')\n");
      destruct(ob);
      return 1;
    }
    online = 0;
  }
  if(ob->query_wiz() && online && ob->query_level() > this_player()->query_level()) {
    tell_object(ob, "[fingered by: "+this_player()->query_name()+"]\n");
  }
  write("\n");
  write(ob->short() + "\n");
  pronoun = capitalize(ob->query_pronoun());
  i = ob->query_wiz();
  type = get_wiz_short(i);
  i = 0;
  write(pronoun + " is a level " + ob->query_level() + " " + type + ".\n");

  if(ob->query_rebirth())
    write(pronoun +" has been reborn. ");

  if(strlen(ob->query_married()))       {
  sscanf(ob->query_married(),"%d %s",m,married);
  if(m) write(pronoun+" is married to "+married+".\n");
                                        }
  if(ob->query_rebirth() && !strlen(ob->query_married()))
  write("\n"); // Linebreakki marriagen ja rebornin j�lkee 

  if(LEADER_D->query_leaderi(ob->query_race()) == lower_case(ob->query_name())) {
    write(pronoun+" leads the "+ob->query_race()+" race.\n");
  }
  
  if(!ob->query_wiz()) {
    tmp = GUILDRANK_D->query_guild_leader(ob);
    if(tmp) write(tmp);

    tmp = GUILDRANK_D->query_rank(ob);
    if(tmp) write(tmp);
  }
  since = time() - ob->query_enter_time();
  if (online && !ob->query_link_dead()) {
    write(pronoun + " has been online for " + stime(since) + "\tIdle: " + stime(ob->idle()) + ".\n");
  }
  if (ob->query_link_dead()) {
    write(pronoun + " has been linkdead for " +stime(since) + ".\n");
  }
  if (!online) {
    write(pronoun + " was last on " +stime(since) + " ago.\n");
  }
  if (ob->query_away()) { write("Away: '"+ob->query_away()+"'.\n"); }
  ob->show_age();
  ob->query_best_kills();
  if (ob->query_plan()) {
    write("Plan:\n");
    write(ob->query_plan());
  } else {
    write("No plan.\n");
  }
  if(this_player()->query_wiz()) {
    string aft_text;
    aft_text = "Total worth: "+ob->query_total_string()+" exp";
    if((this_player()->query_wiz()>2) && (ob->query_email())) 
      aft_text += " (E-mail: "+ob->query_email()+")";
    aft_text += "\n";
    if(interactive(ob)) aft_text += "Host: "+query_ip_name(ob)+" ";
    aft_text += "(Last IP: "+ob->query_last_ip()+")\n";
    write(aft_text);
  /*
    if (ob->query_conversed() != CONVERSE) {
      write("Unconversed: "+ob->query_conversed()+"\n");
    }
  */
  }
  if (!online) {
    destruct(ob);
  }
  return 1;
}

stime(int i) {
  return call_other("/obj/player", "stime", i);
}

get_wiz_short(int i) {
  switch(i) {
  case 0 : return "player";
  case 1 : return "Apprentice wizard";
  case 2 : return "Wizard";
  case 3 : return "Archwizard";
  case 4 : return "Demi-God";
  case 5 : return "God";
  }
}
