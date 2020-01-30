resolve(int bonus, string target) {
  object ob;
  string tmp0,tmp1,tmp2,exp;
  if(!target) {
    tell_object(caster_ob, "You must specify a target.\n");
    return 1;
  }
  ob = present(target, environment(caster_ob));
  if(!ob) {
    tell_object(caster_ob, "No "+target+" present.\n");
    return 1;
  }
  tmp2 = "                                                                   ";
  tmp0 = "+-----------------------------------------------------------------+";
  tmp1 = "| "+ob->short()+"  (Name: "+ob->query_name()+")";
  tell_object(caster_ob, tmp0+"\n");
  tell_object(caster_ob, tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  tmp1 = "| Wc:
  tmp1 = "| Level: "+ob->query_level()+" Exp: "+exp+" Totals: "+ob->query_total_string();
  tell_object(caster_ob, tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  tmp1 = "| Wiz: "+ob->query_wiz()+" Tester: "+ob->query_tester()+
