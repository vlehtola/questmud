#define MASTERY_D "/daemons/mastery_d"
#define MAX_BOOSTS 2

object user;
int duration, effect;
string stat;

string get_attribute(string pref) {
  switch(pref) {
  case "fla": return "wis";
  case "brr": return "int";
  case "sol": return "con";
  case "zzt": return "dex";
  }
  return 0;
}

start(object ob, int boost, string st) {
  object prev;
  user = ob;
  stat = get_attribute(st);
  if(user->query_query_demon()) {
  write("You can't cast this spell at demons.\n");
  destruct(this_object());
  return 1;
  }
  prev = user->query_stat_boost();
  if(user->query_stat_boost_count() >= MAX_BOOSTS || (prev && prev->query_stat() == stat)) {
    write(user->query_name()+" is already enchanted enough.\n");
    destruct(this_object());
    return 0;
  }
  tell_object(user, "You feel more powerful! ("+stat+" increased)\n");
  tell_room(user, user->query_name()+" looks more powerful!\n", ({ user, }) );
  shadow(user, 1);
  /* dur = <5min + 4 min + ~6min ~= max 15 min */
  duration = boost + 4*60 + 2*(this_player()->query_skills("theory of electricity")+this_player()->query_skills("shielding mastery"));
  duration += MASTERY_D->query_mastery("Knowledge of shielding",this_player())*2;
  effect = 40+ (this_player()->query_skills("theory of electricity")+this_player()->query_skills("mastery of protection"))/6;
  effect += random(20) + boost/20;
  if(effect > 120) effect = 120;
  effect += MASTERY_D->mastery("Knowledge of shielding",this_player(),user)/3;
  call_out("end_stat_boost", duration);
  user->update_stats();
}

string query_stat() { return stat; }

query_stat_boost_count() {
  return (user->query_stat_boost_count()+1);
}

query_stat_boost() {
  return this_object();
}

query_str() { return get_boost("str"); }
query_dex() { return get_boost("dex"); }
query_con() { return get_boost("con"); }
query_int() { return get_boost("int"); }
query_wis() { return get_boost("wis"); }

int get_boost(string st) {
  int boost;
  if(st != stat) return call_other(user, "query_"+st);
  boost = call_other(user, "query_"+stat);
  boost += effect;
  return boost;
}

void end_stat_boost() {
  object boost;
  boost = user->query_stat_boost();
  if(boost) {
    boost->end_stat_boost();
    return;
  }
  tell_object(user, "You feel less powerful.\n");
  effect = 0;
  user->update_stats();
  destruct(this_object());
}
