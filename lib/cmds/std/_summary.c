#define HUMANIZE_D "/daemons/humanize_d"

cmd_summary(string str) 
{
  object ob;
  int xp,mo;
  int xp_su,mo_su;

  if(this_player()->query_wiz() && str)
  {
    ob = find_player(str);
    if(!ob) {
        write("No such player. ("+str+")\n");
        return 1;
    }
  }

  if(!ob) { ob = this_player(); }
  xp_su = ob->query_exp_summary();                                                                                                                        
  mo_su = ob->query_money_summary();
  if((time()-ob->query_enter_time())/60) {
    xp=xp_su/((time()-ob->query_enter_time())/60);
    mo=mo_su/((time()-ob->query_enter_time())/60);
  } else {
    xp=xp_su;
    mo=mo_su;
  }

  write("\n");
  write("You have gained ");

  if(!xp_su) 
   write("no experience points and ");
    else
   write( xp_su+"0 experience points ("+ xp*10 +" xp/min) and ");

  if(!mo_su) 
   write("no money ");
    else
   write("money worth "+ mo_su +" bronze coins ("+mo+" bronzes/min) ");

  write("in "+this_player()->stime(time()-ob->query_enter_time())+".\n");
  return 1;                                                                                                                                               
}
