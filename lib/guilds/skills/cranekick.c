get_time() {
  return random(2)+2;
}
ep_cost() { return 10; }
query_type() { return "offensive"; }

resolve_skill(str) {
  int dama;
  string str1,str2;
  object tp,target;
  tp = this_player();
  str1 = ""; str2 = "";
  if(!str) {
    write("Kick whom?\n");
    return 1;
  }
  target = present(str,environment(this_player()));
  if(!target) {
    write(str+" is not a valid target.\n");
    return 1;
  }
  dama = (tp->query_str()+tp->query_dex())*2;
  dama = (tp->query_skills("cranekick")*2/3+tp->query_skills("spinkick")/2
	+present("robes",tp)->query_kata_bonus()/3)*dama/200+dama/10;
  if(tp->query_skills("breath control")+tp->query_skills("cranekick") > random(700)) {
    write("You breath deeply and focus on your kick.\n");
    dama = dama * 3;
  }
  dama = dama*(random(5)+10)/12;
  if (dama > 200) str1 = "relax, ";
  if (dama > 350) str2 = "NASTY ";
  write("You "+str1+"jump up and aim a "+str2+"doublekick to "+target->query_name()+"'s chest.\n");
  say(tp->query_name()+" jumps up and passionately kicks "+target->query_name()+
    " with both of "+tp->query_possessive()+" feet in the chest causing ribs to bend in.\n",target);
  tell_object(target, tp->query_name()+" jumps up and punctures your chest with a NASTY doublekick!\n");
  target->hit_with_spell(dama);
  this_player()->attack_object(target, 1);
  if (target) { target->hit_with_spell(dama/2); }
  return 1;
}

fail_skill(str) {
  object tp,target;
  if(!str) {
    write("Kick whom?\n");
    return 1;
  }
  target = present(str,environment(this_player()));
  if(!target) {
    write(str+" is not a valid target.\n");
    return 1;
  }
  tp = this_player();
  write("You cannot keep the balance to perform the kick in the air.\n");
  say(tp->query_name()+" jumps up and tries to kick "+target->query_name()+
    ", but loses "+tp->query_possessive()+" balance and falls down on his kneels.\n");
  tell_object(target, tp->query_name()+" jumps up and tries to kick you, but misses.\n");
  return 1;
}

