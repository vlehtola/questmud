#define MASTERY_D "/daemons/mastery_d"
object user;
int duration, effect;

hit_player(int damage, arg2,arg3,arg4,arg5,arg6) {
  damage -= effect;
  if(damage < 1) damage = 1;
  if(!random(10)) tell_room(environment(user), "The energy barrier flashes.\n");
  user->hit_player(damage, arg2,arg3,arg4,arg5,arg6);
}

start(object ob, int bonus) {
  user = ob;
  if(user->query_shield_protection()) {
    write(user->query_name()+" is already protected.\n");
    destruct(this_object());
    return 1;
  }
  tell_object(user, "You are now protected by a thin energy barrier.\n");
  shadow(user, 1);
  duration = bonus + 2*60 + 2*(this_player()->query_skills("theory of electricity")+this_player()->query_skills("shielding mastery"));
  duration += MASTERY_D->query_mastery("Knowledge of shielding",this_player())*2;
  /* max 8 */
  effect = 4+ (this_player()->query_skills("theory of electricity")+this_player()->query_skills("mastery of protection"))/50;
  if(effect > 8) effect = 8;
  effect += MASTERY_D->mastery("Knowledge of shielding",this_player(),user)/20;
  call_out("end_shield", duration);
}

query_shield_protection() {
  return this_object();
}

end_shield() {
  tell_object(user, "The energy barrier around you vanishes!\n");
  destruct(this_object());
}  

