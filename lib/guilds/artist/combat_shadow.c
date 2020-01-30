#define EP_TUNE 50

/* epreduce = dam / EPTUNE, eli mita suurempi sita suffelimpi */
object user, robes;
int dam;
string text;

start(ob) {
  if(!ob) destruct(this_object());
  user = ob;
  shadow(user, 1);
}

hit_with_spell(arg,arg2,arg3,arg4,arg5) {
  if(user->query_skills("sixth instinct") > random(500)) {
    tell_room(environment(user), "..but manages to avoid the attack!\n", ({user}));
    tell_object(user, "..but your sixth instinct warns you just before and you manage to avoid the attack!\n");
    return 0;
  }
  user->hit_player(arg,arg2,arg3,arg4,arg5);
}

move_player(arg,arg2,arg3) {
  object ob;
  ob = present("robes", user);
  if(ob) ob->stop_training();
  user->move_player(arg,arg2,arg3);
}

remove_artist() {
  tell_object(user, "You feel like you forgot how to fight.\n");
  destruct(this_object());
}

myllytys() {
  int bonus,hit,tmp,hits,i,power;
  if(user->query_name_of_right_weapon() && user->query_right_weapon()->query_type() != "blade" ||
	user->query_name_of_left_weapon()) {
    write("You cannot fight with these weapons.\n");
    return 0;
  }
  if(user->query_ep() < 1) {
    write("You are too exhausted to fight.\n");
    return 0;
  }
  if(!user->query_npc()) {
    robes = present("robes", user);
    if(!robes) {
      tell_object(user, "You cannot fight without your robes.\n");
      return 0;
    }
  }
  if(check_semo_fail()) return 0;
  bonus = user->query_skills("ambidexterous attack") / 4;
  tmp = user->query_skills("mental balance")+110;
  if(tmp > 190) tmp = 190 + (tmp-190)/2;
  if(tmp < random(200)) {
    tell_object(user, "You cannot help being angry and fail to attack correctly.\n");
    user->attack(80, calculate_damage());
    return 0;
  }
  hits = 2;
  hit = user->query_skills("hit combing");
  hit += user->query_skills("combined martial arts");
  hit -= random(60);
  if(hit > 20) hits += 1;
  if(hit > 90) hits += 1;
  if(hit > 160) hits += 1;
  power = 100;
  if(user->query_skills("breath control") > random(400)) {
    tell_object(user, "You take a deep breath and focus more power on your hits.\n");
    bonus += user->query_skills("breath control");
  }
  while(i < hits) {
    user->attack(power+bonus, calculate_damage());
    power -= 20; /* power tippuu joka iskulla */
    if(power < 10) power = 10;
    i += 1;
  }
  /* special hitit kerran rundis */
  if(call_other("/world/artist/special_hit","resolve_hit",user)) return -1;
}
/* checkaa tasta alaspain */
calculate_damage() {
  int roll,tmp,ep;
  object ob;
  roll = random(100)+1;
  if(roll > 60) {
    dam = call_other("/world/artist/kick","resolve_hit",user)*2;
  } else {
    if(user->query_right_weapon()) {
      dam = call_other("/world/artist/weapon_hit","resolve_hit",user);
    } else {
      dam = call_other("/world/artist/punch","resolve_hit",user);
    }
  }
  dam = dam * (user->query_str()+100) / 100;
  if(robes) user->hit_with_spell(robes->body_damage(dam,roll/50));
  if(!user || !user->query_attack()) return 0;
  ep = user->query_ep();
  dam -= dam*(ep*100/user->query_max_ep());
  if(ep > dam / EP_TUNE) {
    user->reduce_ep(dam/EP_TUNE);
  } else {
    user->reduce_ep(ep);
  }
  return dam;
}

set_text(str) {
  text = str;
}

get_combat_texts() {
  if(text) tell_object(user, text);
  tell_object(user->query_attack(), call_other("/world/artist/combat_texts", "get_text", dam,user));
}
query_artist() {
  return 1;
}
set_stunned(arg,arg2) {
  if(user->query_skills("nerve mastery") > random(100)) {
    tell_object(user, "You control your nerves and ignore the pain.\n");
    if(user->query_attack())
      tell_object(user->query_attack(), user->query_name()+" avoids the stun!\n");
    return 0;
  }
  return user->set_stunned(arg,arg2);
}
