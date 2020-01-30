/*
cast protection:
magical elemental shield
fla/brr/zzt: 50%-80% protti yhelle preffille (mastery dependent)
sol: 2 iskun shieldi, 80% 60% (non-phys damage)
vain yksi naista voi olla paalla
*/
#define MASTERY_D "/daemons/mastery_d"

object user;
int duration, percent, element, hits;

/* semmonen yhteinen funktio, jossa lasketaan hommat. */
calculate_protection() {
  int sk, mast;
  string skill;
  skill = "cast "+element;
  if(element == "non-physical") skill = "cast earth";
  sk = this_player()->query_skills(get_mastery(skill));
  mast = mastery(skill,user);
  mast += MASTERY_D->mastery("Knowledge of shielding",this_player(),user);
  /* max prot = ~80 */
  percent = 50+ (sk + this_player()->query_skills("mastery of protection")+mast) /6;
  /* max dura = ~9 min */
  duration = 60*3 + (sk+this_player()->query_skills("shielding mastery")+mast)*2;
}

mastery(string skill, object us) {
  int m;
  m = 0;
  switch(skill) {
        case "cast fire": m = MASTERY_D->mastery("Dangerous Fire",this_player(),us); break;
        case "cast ice": m = MASTERY_D->mastery("Dangerous Ice",this_player(),us); break;
        case "cast electric": m = MASTERY_D->mastery("Dangerous Lightning",this_player(),us); break;
  }
  return m;
}

get_mastery(string skill) {
  switch(skill) {
  case "cast fire": return "knowledge of heat";
  case "cast ice": return "lore of cold";
  case "cast electric": return "theory of electricity";
  case "cast earth": return "gaian lore";
  }
}

hit_with_spell(int damage, string pref, arg1, arg2, arg3) {
  object player;
  if(!stringp(pref)) {
    log_file("INTP_PREF", ctime(time())+" "+user->query_name()+" pref: "+pref+" prev_ob: "+file_name(previous_object())+"\n");
    player = find_player("celtron");
    if(player) tell_object(player, "illegal pref: "+pref+" prev_ob: "+file_name(previous_object())+"\n");
    /* prevent abuse */
    user->hit_with_spell(damage*2, "physical" ,arg1,arg2,arg3);
    return 1;
  }
  if(pref == element) damage -= (damage * percent) / 100;
  if(element == "non-physical" && pref != "physical") {
    damage -= damage * percent / 100;
    calculate_hits();
  }
  user->hit_with_spell(damage,pref,arg1,arg2,arg3);
}

calculate_hits(int new) {
  if(new) {
    hits = 2;
    return 1;
  }
  hits -= 1;
  percent -= 20;
  if(hits < 1) {
    end_protection();
    return 1;
  }
}

query_protection() {
  return this_object();
}

start(object ob, int bonus, string pref) {
  string str;
  user = ob;
  if(user->query_protection()) {
    write(user->query_name()+" is already protected.\n");
    destruct(this_object());
    return 1;
  }
  tell_object(user, "An elemental shield surrounds you.\n");
  shadow(user, 1);
  if(pref == "zzt") element = "electric";
  if(pref == "fla") element = "fire";
  if(pref == "brr") element = "ice";
  if(pref == "sol") {
    element = "non-physical";
    calculate_hits(1);
  }
  if(element == "ice" || element == "electric") {
        str = "an";
  } else {
        str = "a";
  }
  write("You enchant "+str+" "+element+" shield for "+user->query_name()+"'s protection.\n");
  if(!element) {
    write("Nothing happens.\n");
    destruct(this_object());
    return 1;
  }
  calculate_protection();

  //Cast ice does cold damage, not ice! --Rag 30.11.2003
  if(element == "ice") element = "cold";

  call_out("end_protection", duration);
}

end_protection() {
  tell_object(user, "You feel like your element protection wearing off.\n");
  destruct(this_object());
}
