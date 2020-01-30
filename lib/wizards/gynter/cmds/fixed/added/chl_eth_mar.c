/* ns "parempi" ressi. (eli saa casteri xpaa) 'recode' by Celtron (25.8.2001) */
/* minori on sama mutta casteri ei saa expaa. */

resolve(int bonus, string target, status minor) {
  object ob, r_ob;
  int effect, exp, skills;
  /*
  if (!this_player()->query_tester()) {
    write("Ress is currently offline.\n");
    return 1;
  }
  */

  if (!target) {
    write("Resurrect whom?\n");
    return;
  }
  ob = find_player(lower_case(target));
  if (!ob) {
    write("No such a player.\n");
    return 1; }
  if (!ob->query_dead()) {
    write(capitalize(target) + " is not dead.\n");
    return 1;
  }

  if(minor)
    skills = this_player()->query_skills("cast minor");
  else
    skills = this_player()->query_skills("cast major");
  skills += this_player()->query_skills("cast soul");
  skills += this_player()->query_skills("channel");

  skills += this_player()->query_skills("mastery of medicine")/3;
  skills = skills / 3; /* oletettu max 100 */
  effect = (33 + this_player()->query_wis()/7)*skills/80;
  if (effect < 33) {
    effect = 33;
  }
  if (effect > 66) {
    effect = 66;
  }
  if(!minor)
    exp = ob->query_train_exp() / 600 * effect;
  if (exp > 20000000) {
    exp = 20000000;
  }

// Minimum expgain added by Gynter
  if(exp < 10000)
    exp = 10000;
  r_ob = clone_object("/guilds/spell_obj/ress_object");
  r_ob->start(ob, this_player()->query_name(), effect, exp);

  /* casterille ressin succes estimate */
  effect = effect/10;
  write("You got a feeling that the effect was between "+(effect*10)+"% and "+((effect+1)*10)+"%.\n");
}