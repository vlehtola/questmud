resolve(int bonus, string target, caster_ob) {
  object tp, ob;
  int i,skill, x;
  string tmp,tmp2;
  string res;
  tmp = "*********************";
  tmp2 = ".....................";
  if(!caster_ob)caster_ob=this_player();
  skill = caster_ob->query_skills("cast information")+caster_ob->query_skills("cast trade");
  if(!target) {
    tell_object(caster_ob, "Cast at what?\n");
    return 1;
  }
  ob = present(target, environment(caster_ob));
  if(!ob) {
    tell_object(caster_ob, "No "+target+" here.\n");
    return 1;
  }
  if(!ob->query_weapon()) {
    tell_object(caster_ob, ob->short()+" is not a weapon.\n");
    return 1;
  }
  tell_object(caster_ob, ob->short()+"\n");
  i = ob->query_wc();
  tell_object(caster_ob,"Value: "+ob->query_value()+" bronzes\n");
  tell_object(caster_ob,"Weapon class: ["+extract(tmp,0,i/5)+extract(tmp2,0,20-i/5)+"]\n");
  tell_object(caster_ob,"This weapon does physical damage.\n");
  tell_object(caster_ob, "Wielder receives following stat modifications, according\n"+
        "to his racial abilities.\n");
  tell_object(caster_ob, "Str: "+ob->query_stats("str")+"% Dex: "+ob->query_stats("dex")+
        "% Con: "+ob->query_stats("con")+"%\n"+
        "Int: "+ob->query_stats("int")+"% Wis: "+ob->query_stats("wis")+"%\n"+
        "Spregen: "+ob->query_stats("spregen")+"\n");
  res = ob->query_resists();
  while (x < sizeof(res)) {
	  if(res[x]) {
		  tell_object(caster_ob, "Equipment offers protection against following elements:\n");
		  tell_object(caster_ob, capitalize(res[x])+": ");
		  tell_object(caster_ob, res[x+1]+"%\n");
	  }
	  x += 2;
  }
  return 1;
}