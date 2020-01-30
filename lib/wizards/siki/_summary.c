cmd_summary(string str) {
  object ob;
  int xp,mo;
  int xp_su,mo_su;
  if(this_player()->query_wiz() && str) {
    ob = find_player(str);
    if(!ob) {
        write("No such a player. ("+str+")\n");
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
  write(xp_su+" experience points and ");
  if(this_player()->query_wiz()) { write("("+xp+" xp/min) "); }
  write("money worth "+mo_su+" bronze coins ");
  if(this_player()->query_wiz()) { write("("+mo+" bronzes/min) "); }
  write("in "+this_player()->stime(time()-ob->query_enter_time())+".\n");
  return 1;                                                                                                                                               
}
