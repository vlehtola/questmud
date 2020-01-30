#define MASTERY_D "/daemons/mastery_d"
object user;
int duration, effect;

hit_player(int damage, arg2,arg3,arg4,arg5,arg6) {
  if(arg2 && arg2 != "physical") {
    damage -= effect * damage/100;
  }
  user->hit_player(damage, arg2,arg3,arg4,arg5,arg6);
}

hit_with_spell(int damage, arg2,arg3,arg4,arg5,arg6) {
  if(arg2 && arg2 != "physical") {
    damage -= effect*damage/100;
  }
  user->hit_with_spell(damage, arg2,arg3,arg4,arg5,arg6);
}

short(arg,arg2) {
  if(arg) return user->short(arg, arg2);
  return user->short(arg, arg2)+" [inside a violet sphere]";
}

start(object ob, int bonus) {
  user = ob;
  if(user->query_sphere_of_protection()) {
    write(user->query_name()+" is already protected.\n");
    destruct(this_object());
    return 1;
  }
  tell_object(user, "You are protected by a thick energy barrier.\n");
  shadow(user, 1);
  duration = bonus + 3*60 + 2*(this_player()->query_skills("knowledge of heat")+this_player()->query_skills("shielding mastery"));
  duration += MASTERY_D->query_mastery("Knowledge of shielding",this_player())*2;
  /* max ~1/3 */
  effect = 20+ (this_player()->query_skills("knowledge of heat")+this_player()->query_skills("mastery of protection"))/14;
  if(effect > 35) effect = 35;
  effect += MASTERY_D->mastery("Knowledge of shielding",this_player(),user)/10;
  call_out("end_sphere_of_protection", duration);
}

query_sphere_of_protection() {
  return this_object();
}

end_sphere_of_protection() {
  tell_object(user, "The energy barrier protecting you vanishes!\n");
  destruct(this_object());
}  

