object mina;
int str,con,aika;

start(ob) {
  int skill,i;
  mina = ob;
  shadow(mina, 1);
  i=mina->query_skills("berserk");
  str = (mina->query_skills("rage")*120/100+i)/2;
  con = (mina->query_skills("fury")*120/100+i)/2;
  skill = mina->query_skills("berserk");
  skill += mina->query_con();
  update_stats();
  /* con + skill minuuttia */
  aika = skill * 60 / 20;
  call_out("end_berserk", aika);
  call_out("texti", 20);
}

query_berserk() {
  return 1;
}

query_defend(str) {
  if(str) return 0;
  return 1;
}

hit_player(int arg,arg2,arg3,arg4,arg5,arg6) {
  arg = arg *4/3;
  return mina->hit_player(arg,arg2,arg3,arg4,arg5,arg6);
}

texti() {
  int i;
  string str3, str2;
  string jees;
  object puuh,ob;
  i = random(5);
  if(i==0) {
    str3 = "You jump up and down in anger!\n";
    str2=  mina->query_name()+" jumps up and down in anger!\n";
  } else if(i==1) {
    str3 = "You SCREAM in rage!\n";
    str2= mina->query_name()+" SCREAMS in rage!\n";
  } else if(i==2) {
    str3 = "You strike your chest with your hands and yell: AOAOAOOO\n";
    str2= mina->query_name()+" strikes "+mina->query_possessive()+" chest with "+
	mina->query_possessive()+" hands and yells: AOAOAOOO!\n";
  } else if(i==3) {
    if(mina->query_name_of_weapon()) {
	jees = mina->query_name_of_weapon();
    } else {
	jees = "fist";
    }
    str3= "You swing your "+jees+" around your head and SCREAM!\n";
    str2= mina->query_name()+" swings "+mina->query_possessive()+" "
		+jees+" around "+mina->query_possessive()+" head and SCREAMS!\n";
  } else if(i==4) {
    str3 = "You shout indecent things to all near you!\n";
    str2= mina->query_name()+" shouts indecent things to you!\n";
  }
  puuh = allocate(1);
  puuh[0] = mina;
  tell_object(mina,str3);
  tell_room(environment(mina), str2, puuh);
  if(str+con > random(400)) {
    ob = all_inventory(environment(mina));
    i=0;
    while(i<sizeof(ob)) {
      if(ob[i] && living(ob[i]) && ob[i]->query_npc() &&
	 mina->query_attack() != ob[i]) {
	tell_room(environment(mina), mina->query_name()+" attacks "+
	  ob[i]->query_name()+" with RAGE!\n");
	mina->attack_object(ob[i]);
	i = sizeof(ob);
      }
      i += 1;
    }
  }
  call_out("texti", random(30)+10);
}

calculate_damage(int arg,arg2,arg3,arg4) {
  int i;
  i = mina->calculate_damage(arg,arg2,arg3,arg4);
  i = i*str/(random(40)+25);
  return i;
}

update_stats() {
  mina->update_stats();
  mina->set_con(mina->query_con()+mina->query_con()*con/120);
}

end_berserk() {
  object puuh;
  puuh = allocate(1);
  puuh[0] = mina;
  tell_object(mina, "You fail to continue your rage.\n");
  tell_room(environment(mina), mina->query_name()+" seems nicer.\n", puuh);
  str=0; con=0;
  mina->update_stats();
  destruct(this_object());
  return 1;
}

death(arg) {
  str=0; con=0;
  mina->update_stats();
  mina->death(arg);
  destruct(this_object());
  return 1;
}
