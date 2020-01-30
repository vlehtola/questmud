#define MASTERY_D "/daemons/mastery_d"
#define MAX_DAMAGE      800 // Set to 800 by Celtron 18.01.2004

get_time() {
  return random(2)+2;
}
ep_cost() { return 5; }
query_type() { return "offensive"; }

resolve_skill(str) {
  int dama, tmp;
  string str1,str2;
  object tp,target;
  tp = this_player();
  str1 = ""; str2 = "";
  if(!str) {
    write("use shadow blow at whom?\n");
    return 1;
  }
  if (this_player()->query_attack()) {
    write("You cannot use shadow blow while in combat.\n");
    return 1;
  }

  target = present(str,environment(this_player()));
  if(!target || !living(target) || target == this_player() ) {
    write(str+" is not a valid target.\n");
    return 1;
  }
  dama = (tp->query_str()/2+tp->query_dex());
  dama = (tp->query_skills("shadow blow")*2);
  if (dama > 300) str1 = "scream 'SAKARA' and ";
  if (dama > 600) {
        str2 = "with FORCE ";
  }

  tmp = this_player()->query_skills("focused shadow blow");

  if(tmp > random(300)) {
    write("You breath deeply and focus your shadow blow.\n");
    dama = dama + random(tmp)+tmp;
  }
  dama += MASTERY_D->mastery("Mastery of body focusing",this_player(),target)*7;

  write("You "+str1+"rush your knuckles "+str2+"directly at the "+target->query_name()+"'s back making "+target->query_name()+" totally STUNNED!\n");
  say(tp->query_name()+" rushes his knuckles "+str2+"at "+target->query_name()+"'s back making "+target->query_name()+" totally STUNNED!\n",target);
  tell_object(target, tp->query_name()+" rushes his knuckles "+str2+"at your back making you to become totally STUNNED!\n");

// Tuned by Celtron 18.01.2004

  if(dama > MAX_DAMAGE/2) {
    dama = MAX_DAMAGE/2 + (dama-MAX_DAMAGE/2)/2;
  }
  if(dama > MAX_DAMAGE) {
    dama = MAX_DAMAGE;
  }

//end of tune

  this_player()->attack_object(target, 1);
  target->attack_object(tp, 1);
  target->set_stunned(3+random(4));
  target->hit_with_spell(dama,"physical");
}

fail_skill(str) {
  object tp,target;
  if(!str) {
    write("Use shadow blow at who?\n");
    return 1;
  }
  target = present(str,environment(this_player()));
  if(!target || !living(target) || target == this_player() ) {
    write(str+" is not a valid target.\n");
    return 1;
  }
  tp = this_player();
  write("You try to sneak behing the "+target->query_name()+" but you lose your temper.\n");
  say(tp->query_name()+" tries to slash "+target->query_name()+", but loses "+tp->query_possessive()+" balance and falls down on his kneels.\n");
  tell_object(target, tp->query_name()+" try to rush his knuckles, but misses.\n");
}

