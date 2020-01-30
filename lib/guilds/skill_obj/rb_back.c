object user;
int chance, damage;

id(str) { return str == "round blow object"; }
drop() { return 1; }

start(ob) {
  user = ob;
  chance = 30+user->query_skills("round blow");
  damage = chance*user->query_str()/20;
  call_out("check", 6);
}

check() {
  if(user->query_attack() && chance > random(200)) do_hit();
  call_out("check",20);
}

do_hit() {
  object ob, hits;
  int i,ii;
  string msg, tmp, names;
  msg = "";
  if(!user->query_right_weapon()) {
    tell_object(user, "You need a weapon in your right hand to perform "+
	"the round blow maneuver.\n");
    destruct(this_object());
    return 1;
  }
  ob = all_inventory(environment(user));
  hits = allocate(sizeof(ob));
  names = allocate(sizeof(ob));
  while(i<sizeof(ob)) {
    if(ob[i] && living(ob[i]) && ob[i]->query_attack() == user) {
      hits[ii] = ob[i];
      names[ii] = ob[i]->query_name();
      ii += 1;
    } else {
      ob[i] = 0;
    }
    i += 1;
  }
  msg = names;
  if(sizeof(msg) > 0)
    tmp = msg[sizeof(msg)-1];
  msg = implode(msg,",");
  if(sscanf(msg, "%s,"+tmp, msg) == 1) {
    msg = msg + " and "+tmp;
  }
  tell_object(user, "You hit "+msg+" with your round blow.\n");
  tell_room(environment(user), user->query_name()+" hits "+msg+" with "+
	user->query_possessive()+" round blow.\n", ({user}));
  i = 0;
  while(i<sizeof(hits) && hits[i]) {
    tell_object(hits[i], user->query_name()+" hits you with "+
	user->query_possessive()+" round blow!\n");
    hits[i]->hit_with_spell(damage, "physical");
    i += 1;
  }
  destruct(this_object());
}
