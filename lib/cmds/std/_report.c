// By someone. Rewritten by Nalle. Jan 2004.

/************************************************************************/

cmd_report(str) 
{
  object ob, tp;
  string arg,nimi,msg,msg2;
  tp = this_player();

  msg  = give_string(tp, 0);
  msg2 = give_string(tp, 1);

  if(str) 
   {
    if  (sscanf(str, "%s %s", nimi, arg) != 2) 
	{ 
	 nimi = str; 
	}

    ob = find_player(nimi);

   if(ob) 
    {
     if (arg == "stats") 
	{
         call_other("/cmds/std/_tell", "cmd_tell", nimi+" "+msg2);
         return 1;
        } 
	 else 
	{
         call_other("/cmds/std/_tell", "cmd_tell", nimi+" "+msg);
         return 1;
     	}
    } 
     else 
    if (nimi == "stats") 
    {
     write("You report '"+msg2+"'\n");
     say(tp->query_name() + " reports '"+msg2+"'\n");
     return 1;
    }
  }

  write("You report '"+msg+"'\n");
  say(tp->query_name()+" reports '"+msg+"'\n");
  return 1;
}

/************************************************************************/

string give_string(object player, int stats)
{
 string result;
 object tp;

 tp = player;

 if(stats)
  result = "Str: "+tp->query_str()+" Dex: "+tp->query_dex()+" Con: "+tp->query_con()+" Int: "+
	tp->query_int()+" Wis: "+tp->query_wis()+" Size: "+tp->query_size();
   else
  result = "Hp: "+tp->query_hp()+"("+tp->query_max_hp()+") Sp: "+tp->query_sp()+"("+
	tp->query_max_sp()+") Ep: "+tp->query_ep()+"("+tp->query_max_ep()+")";

 return result;
}
