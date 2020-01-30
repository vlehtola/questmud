object mina;
int dodge,parry, rounds;

start(object ob) {
  int kesto;
  dodge = ob->query_skills("dodge");
  parry = ob->query_skills("parry");
  mina = ob;
  shadow(mina, 1);

  rounds = random(this_player()->query_skills("defend")) /10 +1;
  if(mina->query_tester() || mina->query_wiz())
    tell_object(mina, "Tester info: duration "+rounds+"\n");

  // must have a termination time. Celtron
  call_out("loppu", rounds*2);
}

set_spell() {
  tell_object(mina, "You can't cast spells when concentrating on your defence.\n");
  return 1;
}

query_defend(mixed arg) {
  object att;
  if(!arg) return this_object();

  att = mina->query_attack();
  if(parry > random(150)) {
    tell_object(att, "..but "+mina->query_name()+" blocks your attack!\n");
    tell_object(mina, "..but you block "+att->query_name()+"'s attack just in time.\n");
    reduce_rounds();
    return 1;
  } else if(dodge > random(150)) {
    tell_object(att, "..but "+mina->query_name()+" slips away from your attack range!\n");
    tell_object(mina, "..but you manage to slip away from "+att->query_name()+"'s attack range.\n");
    reduce_rounds();
    return 1;
  }
  return 0;
}

reduce_rounds() {
  rounds -= 1;
  if(rounds > 0) return 1;
  loppu();
}

restore_time_points() {
  reduce_rounds();
  tell_object(mina, "You are defending and are unable to attack.\n");
  return 1;
}

use(mixed arg) {
  if(arg == "defend") {
    tell_object(mina, "You lower your defence.\n");
    loppu();
    return 1;
  }
  tell_object(mina,"You are defending and cannot use any skills.\n");
  return 1;
}

cast() {
  tell_object(mina, "You are defending and cannot cast any spells.\n");
  return 1;
}

loppu() {

//  if(!random(2)) tell_object(mina,"You failed to continue your concentration.\n");
//  else 
  tell_object(mina, "Your concentration breaks.\n");

  destruct(this_object());
}

