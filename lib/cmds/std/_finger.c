#define LEADER_D  "/daemons/leader_d"
#define GUILDRANK_D "/daemons/guildrank_d"
#define INVISIBILITY_D "/daemons/invisibility_d"

cmd_finger(string nam)
{
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
      write("No such player. ('"+capitalize(nam)+"')\n");
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
  if(!ob->query_wiz()) {
    if(ob->query_rebirth() == 1)
      write(pronoun +" has been reborn. ");
    else if(ob->query_rebirth() == 2)
      write(pronoun +" has been reborn twice. ");
    else if(ob->query_rebirth() == 3)
      write(pronoun +" has been reborn three times. ");
  }
  if( ob->query_deceased() )
  {

   catch ( write( ob->query_deceased() + "\n") );
  }

  if(strlen(ob->query_married())) {
   sscanf(ob->query_married(),"%d %s",m,married);
   if(m) write(pronoun+" is married to "+married+".\n");

  }
  if(ob->query_rebirth() && !strlen(ob->query_married()))
  write("\n"); // Linebreakki marriagen ja rebornin jalkee

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

  if(ob->query_invisible())
  {
   write(pronoun + " has been linkdead for "+
         stime(INVISIBILITY_D->give_false_time()) + ".\n");
  }
 else
  { // Invis else bracket
  if (online && !ob->query_link_dead()) {
    write(
        pronoun + " has been online for " + stime(since) + ", idle " +
        stime(ob->idle()) );

  // Away and status lines
  if (ob->query_away())   { write(" (Away '"+ob->query_away()+"')"); }
        else
  if (ob->query_status())
        {
        write(" ('"+ob->query_status()+"')");
        }
  write(".\n");
  }

  if (ob->query_link_dead()) {
    write(pronoun + " has been linkdead for " +stime(since) + ".\n");
  }
  if (!online) {
    write(pronoun + " was last on " +stime(since) + " ago.\n");
  }
 } // Endof invis else bracket


  // Creation dates quickly made by Nalle, Jan 2004
  if(ob->query_created())
   {
    write(pronoun + " was created on "+ctime(ob->query_created())+". ");
    ob->show_age();
   }
   else
   {

    if(ob->query_real_name() == "celtron")
      write(pronoun + " is the creator. ");
     else
      write(pronoun + " was created before 2004. ");

    ob->show_age();
   }

  ob->query_best_kills();

  if (ob->query_plan())
  {
    write("Plan:\n");

        // ">"'s added in front of plan by Nalle '03
        {

        string plan_string,buffy;
        plan_string=ob->query_plan();

         while(strlen(plan_string))
         {
          sscanf(plan_string,"%s\n%s",buffy,plan_string);
          write(">"+buffy+"\n");
         }

        }
  } else {
    write("No plan.\n");
  }
  if(this_player()->query_wiz()) {
    string aft_text;
    // Garath fix 04-11-08
    // aft_text = "Total worth: "+ob->query_total_string()+" exp";
    aft_text = "Total worth: "+get_exp(ob->query_total_string())+" exp";
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
  case 3 : return "Adept wizard";
  case 4 : return "Archwizard";
  case 5 : return "Elder";
  }
}


string give_age(object ob)
{
 string str;

 str = ob->show_age();

 str = str[4 .. (strlen(str)-2) ];

 return str;
}

string get_exp(string str) {
  string tmp_exp,exp_str;
  tmp_exp = str;
  exp_str = "";
  if(tmp_exp && stringp(tmp_exp)) {
    if(strlen(tmp_exp) > 9) {
      exp_str += extract(tmp_exp,0,strlen(tmp_exp)-10)+"G ";
      tmp_exp = extract(tmp_exp,strlen(tmp_exp)-9,strlen(tmp_exp));
    }
    if(strlen(tmp_exp) > 6) {
      exp_str += extract(tmp_exp,0,strlen(tmp_exp)-7)+"M ";
      tmp_exp = extract(tmp_exp,strlen(tmp_exp)-6,strlen(tmp_exp));
    }
    if(strlen(tmp_exp) > 3) {
      exp_str += extract(tmp_exp,0,strlen(tmp_exp)-4)+"k ";
      tmp_exp = extract(tmp_exp,strlen(tmp_exp)-3,strlen(tmp_exp));
    }
  }
  if(strlen(tmp_exp) < 3) {
    exp_str += extract("0000", 1, 3-strlen(tmp_exp)) + tmp_exp;
  } else {
    exp_str += tmp_exp;
  }
  if(exp_str == "") {
    exp_str = "0k";
  }
  return exp_str;
}
