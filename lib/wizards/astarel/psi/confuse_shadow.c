object tgt;

start(ob,time) {
  tgt = ob;
  shadow(tgt, 1);
  call_out("end_confuse",time); 
  call_out("confused", 10);
  call_out("messaget", 5);
  tell_room(environment(tgt),tgt->query_name()+" gets confused and starts wander aroung the room mumbling something.\n");
}

messaget() {
	
string *messut;

messut = ({tgt->query_name()+" wanders around mumbling something stupid.\n",
           tgt->query_name()+" mumbles something stupid.\n",
           tgt->query_name()+" gets really stupid look on "+tgt->query_possessive()+" and almost confuses you!\n",
        });
        
tell_room(environment(tgt),messut[random(sizeof(messut))]);

call_out("messaget",5+random(10));

}
	

set_spell() {
return 1;
}
set_skill() {
return 1;
}


confused() {
 int i;
 object ob;
 // NOTE: lis�� t�h�n confuse-messut
    ob = all_inventory(environment(tgt));
    i=0;
    while(i<sizeof(ob)) {
        
      if(ob[i] && living(ob[i]) && tgt->query_attack() != ob[i] && !ob[i]->query_animal_ob() && ob[i] != tgt) {
        tell_room(environment(tgt), tgt->query_name()+" is confused and attacks against "+ob[i]->query_name()+"!\n");
        tgt->attack_object(ob[i]);
        i = sizeof(ob);
      }
      i += 1;
    }
 
i = random(30)+10;
  call_out("confused",i);
}

end_confuse() {
  
  tell_room(environment(tgt),tgt->query_name()+" is no longer confused.\n");
  destruct(this_object());
  return 1;

}

death(arg) {
  tgt->death(arg);
  if(this_object()) destruct(this_object());
  return 1;
}
