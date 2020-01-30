object mina;
int str,con,aika;

start(ob) {
  int skill,i;
  mina = ob;
  shadow(mina, 1);
  i=mina->query_skills("berserk");
  str = mina->query_skills("rage")+i;
  con = (mina->query_skills("fury")+i)/2;
  con -= con/10;
  skill = mina->query_skills("berserk");
  skill += mina->query_con();
  mina->update_stats();
  /* con + skill minuuttia */
  update_stats();
  aika = skill * 60 / 20;
  call_out("end_berserk", aika);
  call_out("texti", 20);
}

set_spell() {
  tell_object(mina, "Your frenzy breaks your casting attempt.\n");
  return 1;
}

move_player(arg,arg2,arg3,arg4,arg5) {
  if(mina->query_attack()) {
    tell_object(mina, "You are in killing frenzy and unwilling to leave!\n");
    return 1;
  }
  mina->move_player(arg,arg2,arg3,arg4,arg5);
}

query_berserk(string type, int dam) {
  if(!type) return 1; /* pelkk^D onko bersua vai ei */
  if(type == "hit") {
    /* [10,30] */
    return (str/10)+10;
  }
  if(type == "damage") {
    return (dam*str / 200)+5;
  }
}

query_defend(arg) {
  if(arg) return 0;
  return 1;
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
        /* query_animal_ob : tame animal object shadow */
      if(ob[i] && living(ob[i]) && ob[i]->query_npc() != mina->query_npc() &&
mina->query_attack() != ob[i] && !ob[i]->query_animal_ob() && !ob[i]->query_necro_horde() && !ob[i]->query_demon()) {

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

update_stats() {
  mina->update_stats();
  mina->set_con(mina->query_con()+mina->query_con()*con/160+10);
  mina->set_str(mina->query_str()+mina->query_str()*str/600+2);
}

link_death(arg,arg2,arg3,arg4) {
  mina->link_death(arg,arg2,arg3,arg4);
  if(mina->query_link_dead())
    end_berserk();
}

end_berserk() {
  object puuh;
  puuh = allocate(1);
  puuh[0] = mina;
  tell_object(mina, "You fail to continue your rage.\n");
  tell_room(environment(mina), mina->query_name()+" seems nicer.\n", puuh);
  str=0; con=0;
  mina->update_stats();
  mina->add_hp(1);
  destruct(this_object());
  return 1;
}

death(arg) {
  str=0; con=0;
  mina->update_stats();
  mina->death(arg);
  if(this_object()) destruct(this_object());
  return 1;
}
