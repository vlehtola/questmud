object mina;
int str,con,dex,aika;

start(ob) {
  int skill,i;
  mina = ob;
  shadow(mina, 1);
  i=mina->query_skills("focus elements");
  str = (mina->query_skills("power of fire")+i)/2;
  con = (mina->query_skills("power of ice")+i)/2;
  con -= con/10;
  dex = (mina->query_skills("power of thunder")+i)/2;
  skill = mina->query_skills("focus elements");
  skill += mina->query_dex();
  /* dex + skill minuuttia */
  update_stats();
  aika = skill * 60 / 20;
  call_out("end_focus_elements", aika);
  call_out("texti", 20);
}

set_spell() {
  tell_object(mina, "Your elemental focusing breaks your casting attempt.\n");
  return 1;
}

move_player(arg,arg2,arg3,arg4,arg5) {
  if(mina->query_attack()) {
    tell_object(mina, "Your elements stops you from fleeing!\n");
    return 1;
  }
  mina->move_player(arg,arg2,arg3,arg4,arg5);
}

hit_player(int arg,arg2,arg3,arg4) {
  mina->hit_player((arg*(450+str)/450),arg2,arg3,arg4);
}

query_focus_elements(string type, int dam) {
  if(!type) return 1; /* pelkk^D onko focusia vai ei */
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

query_seal_wounds(arg) {
  if(arg) return 0;
write("Your elements breaks your sealing attempt.");
  return 1;
}
texti() {
  int i;
  string str3, str2;
  string jees;
  object puuh,ob;
  i = random(3);
  if(i==0) {
    str3 = "Your knuckles sizzles a bit!\n";
    str2=  mina->query_name()+" knuckles flashes!\n";
  } else if(i==1) {
    str3 = "Your eyes turns to red!\n";
    str2= mina->query_name()+" eyes turns to red!\n";
  } else if(i==2) {
    str3 = "You move your hands up and scream 'SANTSEN SO'\n";
    str2= mina->query_name()+" moves his hands up and screams 'SANTSEN SO'!\n";
  }
}

update_stats() {
  mina->update_stats();
  mina->set_con(mina->query_con()+mina->query_con()*con/250+10);
  mina->set_str(mina->query_str()+mina->query_str()*str/450+2);
  mina->set_dex(mina->query_dex()+mina->query_dex()*dex/250+5);
}

link_death(arg,arg2,arg3,arg4) {
  mina->link_death(arg,arg2,arg3,arg4);
  if(mina->query_link_dead());
    end_focus_elements();
}

end_focus_elements() {
  object puuh;
  puuh = allocate(1);
  puuh[0] = mina;
  tell_object(mina, "Your elements leaves from you.\n");
  tell_room(environment(mina), mina->query_name()+"'s elements vanishes.\n", puuh);

  str=0; con=0; dex=0;
  mina->update_stats();
  mina->add_hp(1);
  destruct(this_object());

  return 1;
}

death(arg) {
  str=0; con=0; dex=0;
  mina->update_stats();
  mina->death(arg);
  if(this_object()) destruct(this_object());
  return 1;
}

