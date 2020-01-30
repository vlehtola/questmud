// coded by C

cmd_summaryall(arg) {
  object ob;
  if(arg == "exp") {
    display("query_exp_summary");
    return 1;
  }
  if(arg == "money") {
    display("query_money_summary");
    return 1;
  }
  write("Usage: summaryall [ money | exp ]\n");
  return 1;
}

display(arg) {
  object ob;
  string str,tmp,tmp2;
  int i,num,tim;
  ob = users();
  write("Displaying "+arg+" for "+sizeof(ob)+" users:\n");
  write("Name:\t\t\tSummary:\t\tX/min\t\tStatus:\n");
  while(i<sizeof(ob)) {
    num = call_other(ob[i], arg);
    str = "";
    if(ob[i]->query_tester()) str = "(tester)";
    if(ob[i]->query_wiz()) str = "(wizard)";
    if(strlen(ob[i]->query_name()) < 8) tmp = "\t\t\t";
    else if(strlen(ob[i]->query_name()) < 16) tmp = "\t\t";
    else tmp = "\t";
    if(num < 10000000) tmp2 = "\t\t\t";
    else tmp2 = "\t\t";
    tim = (time()-ob[i]->query_enter_time())/60;
    if(tim < 1) tim = 1;
    num=num/100;
    write(ob[i]->query_name()+tmp+num+"k"+tmp2+
	(num/tim)+"k\t\t"+str+"\n");
    i += 1;
  }
  write("Done listing.\n");
  return 1;
}
