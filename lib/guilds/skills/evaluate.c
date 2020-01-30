examine_weapon(object ob) {
  int i,skill, limit;
  string tmp,tmp2, tmp3;
  tmp =  "##################################################";
  tmp2 = "..................................................";
  tmp3 = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
  write("Type: "+ob->query_type()+"\n");
  /* minimi wc on 30 */
  i = skill_limit(ob->query_wc() - 30);
  write("         Low                               High\n");
  write("Damage: ["+extract(tmp,0,i/2)+extract(tmp2,0,60-i/2)+"]\n");
  /* hit bonus [0,140] */
  i = skill_limit(ob->query_hit_bonus()/3);
  limit = 33;
  if(i > limit) {
    skill = i - limit;
    i = limit;
    write("To hit: ["+extract(tmp3,0,i)+extract(tmp,0,skill)+extract(tmp2,0,(35-i+skill) )+"]\n");
  } else {
    write("To hit: ["+extract(tmp3,0,i)+extract(tmp2,0,35-i)+"]\n");
  }
  write("\n");
  return 1;
}

examine_armour(ob) {
  int i,skill;
  string tmp,tmp2;
  tmp = "*********************";
  tmp2 = ".....................";
  write("Slot: "+ob->query_slot()+"\n");
  i = skill_limit(ob->query_ac());
  write("Quality: ["+extract(tmp,0,i/5)+extract(tmp2,0,20-i/5)+"]\n");
  write("Your armour class is the average of the slots with a defensive need.\n");
  write("Critical hits check only the armour of one slot.\n");
  return 1;
}

skill_limit(int i) {
  int skill;
  skill = this_player()->query_skills("evaluate");
  if(i>skill) {
    write("Your limited knowledge can't figure out everything about this item.\n");
    i = skill;
  }
  return i;
}

get_time() {
  return 10;
}

ep_cost() {
  return 0;
}
query_type() { return "neutral"; }

resolve_skill(eq) {
  int i;
  object ob;
  if(!eq) {
    write("Use appraise on what item?\n");
    return 1;
  }
  ob = present(eq, this_player());
  if(!ob) {
   write("You don't have any "+eq+".\n");
   return 1;
  }
  if(ob->query_wc()) {
    write(ob->short()+" is a weapon; ");
    examine_weapon(ob);
    return 1;
  }
  if(ob->query_ac()) {
    write(ob->short()+" is an armour; ");
    examine_armour(ob);
    return 1;
  }
  write("You can't figure anything out of "+ob->short()+",\n");
  write("but surely it won't give any benefit in combat.\n");
  return 1;
}

fail_skill(eq) {
  write("You can't figure anything out of this item.\n");
}

