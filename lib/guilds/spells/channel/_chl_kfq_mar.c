/* Heal all //Celtron */
/* this spell is not meant to be chained to get mastery */

#define HEAL    120
#define MASTERY_D "/daemons/mastery_d"

status needs_to_be_healed(object user) {
  if(!user->query_max_hp()) return 0;
  return !(user->query_hp() / user->query_max_hp());
}

resolve(int bonus, string target) {
  object *ob;
  int i, sp, hp;
  ob = filter_array(users(), "needs_to_be_healed");
  sp = this_player()->query_sp();
  for(i=0; i < sizeof(ob) && sp > 0; i++) {
    tell_object(ob[i], "You feel a tender healing force closing up your wounds.\n");
    hp = ob[i]->query_max_hp() - ob[i]->query_hp();
    if(hp > HEAL) hp = HEAL;

    if(sp >= hp) {
      ob[i]->heal_hp(hp);
      sp -= hp;
    } else {
      ob[i]->heal_hp(sp);
      sp = 0;
    }
  }
  this_player()->reduce_sp(this_player()->query_sp() - sp);
  write("You healed "+sizeof(ob)+" players.\n");
}
