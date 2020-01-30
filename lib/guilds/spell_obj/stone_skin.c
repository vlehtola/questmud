//Added neverending stone_skin for special eq --Rag
#define MASTERY_D "/daemons/mastery_d"
object user;
int duration, effect;

query_slot_ac(arg,arg2) {
  int ac;
  ac = user->query_slot_ac(arg,arg2);
  ac += effect;
  if(ac > 130) ac = 130;
  return ac;
}

start(object ob, int bonus) {
  user = ob;
  if(user->query_stone_skin()) {
    write(user->query_name()+" is already protected.\n");
    destruct(this_object());
    return 1;
  }
  tell_object(user, "Your skin transforms into solid stone!\n");
  shadow(user, 1);
  duration = bonus + 60 + 2*(this_player()->query_skills("theory of electricity")+this_player()->query_skills("shielding mastery"));
  duration += MASTERY_D->query_mastery("Knowledge of shielding",this_player(),user)*2;
  effect = 25+ (this_player()->query_skills("theory of electricity")+this_player()->query_skills("mastery of protection"))/12;
  if(effect > 40) effect = 40;

  effect += MASTERY_D->mastery("Knowledge of shielding",this_player(),user)/10;
  
  if(bonus == -1)
    effect = 30;

  if(bonus != -1)
    call_out("end_stone_skin", duration);
}

query_stone_skin() {
  return this_object();
}

end_stone_skin() {
  tell_object(user, "Your skin suddenly appears to be normal again.\n");
  destruct(this_object());
}  

