resolve(int bonus, string target) {
  object tp, ob;
  int i,skill;
  string tmp,tmp2;
  tmp = "*********************";
  tmp2 = ".....................";

  tp = this_player();
  skill = tp->query_skills("cast information")+tp->query_skills("cast trade");
  if(!target) {
    write("Cast at what?\n");
    return 1;
  }
  ob = present(target, environment(tp));
  if(!ob) {
    write("No "+target+" here.\n");
    return 1;
  }
  if(!ob->query_weapon()) {
    write(ob->short()+" is not a weapon.\n");
    return 1;
  }
  i = ob->can_wield(this_player()->query_size());
  write(ob->short()+"\n");
  write("Value: "+ob->query_value()+" bronzes\n");
  write("It is a "+ob->query_type()+" type of weapon and it's a "+ob->query_size()+" sized.\n");
  write("It is made of "+ob->query_material()+" and it's of "+call_other("/wizards/neophyte/weapon_sub_types", "query_class_adjective", ob->query_class())+" quality.\n");
  write("It increase's weapon class "+get_wc(ob->query_wc()/10)+".\n");
  write("It increase's hit chance "+get_spec(ob->query_to_hit())+".\n");
  write("It increase's damage "+get_spec(ob->query_to_damage())+".\n");
  if(ob->query_stats("str")) write("It increase's strength "+get_spec(ob->query_stats("str"))+".\n");
  if(ob->query_stats("dex")) write("It increase's dexterity "+get_spec(ob->query_stats("dex"))+".\n");
  if(ob->query_stats("con")) write("It increase's constitution "+get_spec(ob->query_stats("con"))+".\n");
  if(ob->query_stats("wis")) write("It increase's wisdom "+get_spec(ob->query_stats("wis"))+".\n");
  if(ob->query_stats("int")) write("It increase's intelligence "+get_spec(ob->query_stats("int"))+".\n");
  if(ob->query_slayer()) write("It is a "+ob->query_slayer()+" slayer.\n");
  if(i==1) { write("It looks like you can wield it in one hand.\n"); return 1; }
  if(i==2) { write("It looks like you need both hands to wield it.\n"); return 1; }
}

get_spec(int i) {
	switch(i) {
	case 0: return "almost nothing";
	case 1: return "very little";
	case 2: return "little";
	case 3: return "tiny";
	case 4: return "below average";
	case 5: return "average";
	case 6: return "above average";
	case 7: return "much";
	case 8: return "quite much";
	case 9: return "greatly";
	case 10: return "insane";
}
}


get_wc(int i) {
	switch(i) {
			case 0: return "nothing";
			case 1: return "very little";
			case 2: return "little";
			case 3: return "tiny";
			case 4: return "below average";
			case 5: return "average";
			case 6: return "above average";
			case 7: return "much";
			case 8: return "quite much";
			case 9: return "greatly";
			case 10: return "insane";
}
return "Tune";
}
