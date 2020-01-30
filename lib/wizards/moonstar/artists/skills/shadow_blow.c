get_time() {
  return random(2)+2;
}
ep_cost() { return 5; }
query_type() { return "offensive"; }

resolve_skill(str) {
  int dama;
  string str1,str2;
  object tp,target;
  tp = this_player();
  str1 = ""; str2 = "";
  if(!str) {
    write("use shadow blow at whom?\n");
    return 1;
  }
  target = present(str,environment(this_player()));
  if(!target) {
    write(str+" is not a valid target.\n");
    return 1;
  }
  dama = (tp->query_str()/2+tp->query_dex());
  dama = (tp->query_skills("shadow blow")*2 + dama/7);
  if(tp->query_skills("focused shadow blow") > random(400)) {
    write("You relax and focus your shadow blow!\n");
    dama = dama + 200;
  }
  dama = dama*(random(5)+10)/13;
  if (dama > 300) str1 = "scream 'SAKARA' and";
  if (dama > 550) {dama = 600;} str2 = "with FORCE";
  write("You "+str1+"rush your knuckles directly at the "+target->query_name()+"'s back making "+target->query_name()+" totally STUNNED!\n");
 say(tp->query_name()+" rushes his knuckles "+str2+" at "+target->query_name()+"'s back making "+target->query_name()+" totally STUNNED!\n",target);
  tell_object(target, tp->query_name()+" rushes his knuckles "+str2+" at "+target->query_name()+"'s back making "+target->query_name()+" totally STUNNED!\n");
        target->hit_with_spell(dama);
        this_player()->attack_object(target, 1);
        target->set_stunned(2+random(4));
        target->attack_object(this_player(),1);
  return 1;
}

fail_skill(str) {
  object tp,target;
  if(!str) {
    write("use shadow blow at who?\n");
    return 1;
  }
  target = present(str,environment(this_player()));
  if(!target) {
    write(str+" is not a valid target.\n");
    return 1;
  }
  tp = this_player();
  write("You try to sneak behing the "+target->query_name()+" but you lose your temper.\n");
  say(tp->query_name()+" tries to slash "+target->query_name()+", but loses "+tp->query_possessive()+" balance and falls down on his kneels.\n");
  tell_object(target, tp->query_name()+" try to rush his knuckles, but misses.\n");
  return 1;
}

