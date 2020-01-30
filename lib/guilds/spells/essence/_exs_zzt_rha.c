/* money is power , raha -> exp */

#define SKILL "mastery of commerce"

resolve(bonus, target, caster_ob) {
  object ob;
  int cash, exp, totals;
  if(target) {
    ob = present(target, environment(caster_ob));
    if(!ob) {
      tell_object(caster_ob, target+" is not here.\n");
      return 1;
    }
  }
  if(!ob) ob = caster_ob;
  cash = ob->query_money(3); /* bronze coins */
/* Ettei mee yli integer rajan */
  if (cash > 10000) { cash = 10000; }
  /* [bronzes] * ( [300,600] + [0,600] ) = exp */
  if(bonus > 600) bonus = 600;

// tuned by Celtron 09.04.2004 (effect halved)
  exp = cash * (bonus + caster_ob->query_skills(SKILL)*3);

  if(12 - (caster_ob->query_skills(SKILL)/10) > random(30)) {
    tell_object(caster_ob, "You feel something went a little wrong..\n");
    exp = exp / 3 * 2;
  }
  if(ob != caster_ob) {
    tell_object(caster_ob, "The effect is reduced due NOT casting the spell at yourself.\n");
    exp = exp *2/3; /* -33% */
  }
  // jos worthii on alle giga, niin costi on redusoitu ++ Celtron 01.03.04
  if(strlen(ob->query_total_string()) < 10) {
    totals = to_int(ob->query_total_string());
    totals = totals / 10000000;
    write("Because "+ob->query_name()+" is inexperienced, the spell's effect is only "+totals+"%.\n");
    exp = exp * totals / 100;
  }
  if(!ob->query_ghost()) ob->add_party_exp(exp); /* muut pmemberit ei saa osaa */
  ob->reduce_money(cash, 3);
  tell_room(environment(caster_ob),
	cash + " bronze worth of "+ob->query_name()+"'s coins vanish!\n", ({caster_ob}));
}
