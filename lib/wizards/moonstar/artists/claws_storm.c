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
    write("claws storm at whom?\n");
    return 1;
  }
  target = present(str,environment(this_player()));
  if(!target) {
    write(str+" is not a valid target.\n");
    return 1;
  }
  dama = (tp->query_str()+tp->query_dex())*2;
  dama = (tp->query_skills("claws storm")*2/3+tp->query_skills("dragon blow")/2 + dama/10);
  if(tp->query_skills("whirlwind") > random(300)) {
    write("You jump in the air and whirl in RAGE.\n");
    dama = dama + 100;
  }
  dama = dama*(random(5)+10)/13;
  if (dama > 200) str1 = "relax and";
  if (dama > 350) {dama = 400;} str2 = "with FORCE";
  write("You "+str1+" whirl your knuckles "+str2+" inside "+target->query_name()+"'s chest.\n");
 say(tp->query_name()+" whirls his knuckles "+str2+"and passionately slashes "+target->query_name()+
    " in the chest causing ribs to bend in.\n",target);
  tell_object(target, tp->query_name()+" whirls his knuckles "+str2+" and punctures your chest with a CRUSHING claws storm!\n");
  target->hit_with_spell(dama);
  this_player()->attack_object(target, 1);
  if (target) { target->hit_with_spell(dama/2); }
  return 1;
}

fail_skill(str) {
  object tp,target;
  if(!str) {
    write("claws storm at whom?\n");
    return 1;
  }
  target = present(str,environment(this_player()));
  if(!target) {
    write(str+" is not a valid target.\n");
    return 1;
  }
  tp = this_player();
  write("You cannot keep the balance to perform the claws storm.\n");
  say(tp->query_name()+" tries to slash "+target->query_name()+", but loses "+tp->query_possessive()+" balance and falls down on his kneels.\n");
  tell_object(target, tp->query_name()+" whirl his knuckles, but misses.\n");
  return 1;
}
