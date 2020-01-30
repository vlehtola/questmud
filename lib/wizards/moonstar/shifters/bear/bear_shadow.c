#define EP_TUNE 200

/* epreduce = dam / EPTUNE, eli mita suurempi sita suffelimpi */
object user;
int dam;
string text;

start(ob) {
  if(!ob) destruct(this_object());
  user = ob;
   tell_object(user, "You transform yourself to bear!\n");
   user->update_stats();
  shadow(user, 1);
}

short() {
        return "A HUGE grizzly bear called "+user->query_name();
}

long()  {
      write("Iso paha poika joka juoksee ympari taloa. Muahahahahah.\n");
}

query_str() {
        return user->query_str()+300;
}

query_con() {
        return user->query_con()+300;
}
query_dex() {
        return user->query_dex()+150;
}

hit_with_spell(arg,arg2,arg3,arg4,arg5) {
  if(user->query_skills("animal instinct") > random(500)) {
    tell_room(environment(user), "..but manages to avoid the attack!\n", ({user}));
    tell_object(user, "..but your animal instinct warns you just before and you manage to avoid the attack!\n");
    return 0;
  }
  user->hit_player(arg,arg2,arg3,arg4,arg5);
}

remove_shifters() {
  tell_object(user, "You feel like you turn back to human.\n");
  destruct(this_object());
}

myllytys() {
  int bonus,hit,tmp,hits,i,power,roll;
  if(user->query_name_of_right_weapon() && user->query_right_weapon()->query_type() == "blade" ||
        user->query_name_of_left_weapon()) {
    write("You cannot fight with these weapons.\n");
    return 0;
  }
  if(user->query_ep() < 1) {
    write("You are too exhausted to fight.\n");
    return 0;
  }
  bonus = user->query_skills("animals strength") / 4;
  tmp = user->query_skills("shapesift control")+110;
  if(tmp > 190) tmp = 190 + (tmp-190)/2;
  if(tmp < random(200)) {
    tell_object(user, "You cannot help being angry and fail to attack correctly.\n");
    user->attack(80, calculate_damage());
    return 0;
  }
  hits = 2;
  hit = user->query_skills("double claws");
  hit += user->query_skills("combined claw strike");
  hit -= random(60);
  if(hit > 20) hits += 1;
  if(hit > 90) hits += 1;
  if(hit > 160) hits += 1;
  power = 100;
  if(user->query_skills("mastery of shapeshifting") > random(400)) {
    tell_object(user, "Your mastery of shapeshifting gives you more power on your hits.\n");
    bonus += user->query_skills("mastery of shapeshifting");
  }
  while(i < hits) {
    user->attack(power+bonus, calculate_damage());
    power -= 20; /* power tippuu joka iskulla */
    if(power < 10) power = 10;
    i += 1;
  }
  roll = random(100)+1;
  if(roll > 50 && roll < 91) {
    if(call_other("/wizards/moonstar/shifters/bear/bear_hug","resolve_hit",user)) return -1;
  } else if(roll > 90) {
    if(call_other("/wizards/moonstar/shifters/bear/bear_strike","resolve_hit",user)) return -1;
  } else {
    if(call_other("/wizards/moonstar/shifters/bear/bear_blow","resolve_hit",user)) return -1;
  }
 
}
/* checkaa tasta alaspain */
calculate_damage(){
  int tmp,ep;
  object ob;
  dam = dam + (user->query_str()+100) / 100;
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
  tell_object(user->query_attack(), call_other("/wizards/moonstar/shifters/bear/combat_texts.c", "get_text", dam,user));
}
query_shifter() {
  return 1;
}
set_stunned(arg,arg2) {
  if(user->query_skills("animals will") > random(170)) {
    tell_object(user, "Your animals will allows you to ignore the pain.\n");
    if(user->query_attack())
      tell_object(user->query_attack(), user->query_name()+" avoids the stun!\n");
    return 0;
  }
  return user->set_stunned(arg,arg2);
}


