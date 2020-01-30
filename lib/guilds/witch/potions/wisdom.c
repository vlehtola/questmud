#include "/guilds/witch/effects.c"
int bonus,time;
object tp;

start(int bon, object ob) {
  tp = ob;
  bonus = bon;
  time = bonus*12+60;
  if(this_player()->query_wis_effect()) {
          tell_object(tp,"Nothing happens.\n");
          destruct(this_object());
          return 1;
  }
  shadow(tp, 1);
  update_stats();
  call_out("end_wis_effect", time);
  tell_object(tp, "You feel your wisdom is rising.\n");
  return 1;
}
query_wis_effect() {
        return this_object();
}
update_stats() {
        tp->update_stats();
        tp->set_wis(tp->query_wis()+(STAT_CALC));
}
end_wis_effect() {
        tell_object(tp, "You feel your wisdom lowering.\n");
        tp->update_stats();
        destruct(this_object());
return 1;
}
