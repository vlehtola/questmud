#define MAX_DAMAGE 1500
int time;

get_time() {
  time = random(5) + 5;
  if(this_player()->query_mastery()["Offensive maneuvers"] > 50) { time = (time - random(1)); }
}

query_type() { return "offensive"; }
ep_cost() { return 7+random(5);  }

resolve_skill(string str) {
  int damage, skills;
  object tp, target;
  if (!this_player()->query_right_weapon()) {
    write("You need a weapon in your right hand to perform this skill.\n");
    return 1;
  }
  if(!str) {
    write("Use tremendous blow at whom?\n");
    return 1;
  }
  target = present(str, environment(this_player()));
  if(!target || !living(target)) {
    write(capitalize(str)+" is not a valid target.\n");
    return 1;
  }
  tp = this_player();
  damage = tp->query_str()*2+tp->query_dex()+100;
  damage = damage*tp->query_right_weapon()->query_wc()/50;
  skills = (tp->query_skills("tremendous blow")+
	tp->query_skills(tp->query_right_weapon()->query_type()+"s"))/2;
  damage = damage*skills/50;
  damage = damage/2 + (damage/2*tp->query_skills("strike")/70);
/* mastery */
     if(random(1000) == 0) {
     this_player()->set_mastery("Offensive maneuvers",(this_player()->query_mastery()["Offensive maneuvers"] + 1));
   }
    if(this_player()->query_mastery()["Offensive maneuvers"]) damage += this_player()->query_mastery()["Offensive maneuvers"];


  if(damage > MAX_DAMAGE) damage = MAX_DAMAGE;
  /* jos kesken combatin bersussa */
  if(this_player()->query_berserk() /* && this_player()->query_attack() */) {
    write("The taste of blood fills your mouth as you focus your fury to the blow.\n");
  } else if(!this_player()->query_berserk()) {
    /* jos ei oo bersuu ni damaa pois */
    damage -= damage /3;
  }
  write("You concentrate for a long time searching for the right timing and suddenly\n");
  write("score a "+get_adj(damage)+" blow to "+target->query_name()+"'s chest!\n");
  tell_object(target, tp->query_name()+" suddenly scores a "+get_adj(damage)+" hit to your chest\n"+
	" causing infite amount of impaling pain!\n");
  tell_room(environment(tp), tp->query_name()+" suddenly hits "+target->query_name()+
	" with a "+get_adj(damage)+" blow!\n", ({tp,target}));
  this_player()->attack_object(target, 1);
  target->hit_with_spell(damage);
}

get_adj(int i) {
  switch(i) {
  case MAX_DAMAGE * 0 / 10 .. MAX_DAMAGE * 3 / 10 -1: return "swift";
  case MAX_DAMAGE * 3 / 10 .. MAX_DAMAGE * 5 / 10 -1: return "powerful";
  case MAX_DAMAGE * 5 / 10 .. MAX_DAMAGE * 7 / 10 -1: return "barbarical";
  case MAX_DAMAGE * 7 / 10 .. MAX_DAMAGE * 9 / 10 -1: return "devastating";
  case MAX_DAMAGE * 9 / 10 .. MAX_DAMAGE * 10 / 10 : return "tremendous";
  }
  return "maximal";
}

fail_skill(str) {
  object target;
  if (!str) { write("You fail the skill.\n"); return; }
  target = present(str, environment(this_player()));
  if (!target) { write("You fail the skill.\n"); return; }
  write("You are not focused enough and miss " + target->query_name() + ".\n");
  tell_object(target, this_player()->query_name() + " tries to STRIKE you, but misses.\n");
  say(capitalize(this_player()->query_name()) + " stumbles towards " + capitalize(target->query_name()) + " and strikes air.\n", target);
  target->attack_object(this_player());
}
