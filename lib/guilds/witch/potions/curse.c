#include "/guilds/witch/effects.c"
object tp;
int time,bonus;

start(int bon, object ob) {
  tp = ob;
  bonus = bon;
  time = (bonus*6)+random(30);
  if(tp->query_curse()) { destruct(this_object()); return 1; }
  shadow(tp, 1);
  update_stats();
  tell_object(tp, "You feel cursed.\n");
  call_out("end_curse", time);
  call_out("curse", random(120));
  return 1;
}

query_curse() { return this_object(); }

curse() {
        if(tp->query_ghost()) { update_stats(); destruct(this_object()); return 1; }
        if(random(25) > bonus) {
                tell_object(tp, "You feel immensive pain in your head and you drop unconscious.\n");
            say(tp->query_name()+ " drops on the ground holding "+ tp->query_possessive()+ " head.\n");
                tp->set_stunned(random(bonus));
                call_out("curse", random(120));
                return 1;
        }
        call_out("curse", random(120));
}

update_stats() {
        tp->update_stats();
        tp->set_str(tp->query_str()/2);
        tp->set_dex(tp->query_dex()/2);
        tp->set_con(tp->query_con()/2);
        tp->set_int(tp->query_int()/2);
        tp->set_wis(tp->query_wis()/2);
}
end_curse() {
        tell_object(tp, "You feel your curse leaving.\n");
        tp->update_stats();
        destruct(this_object());
        return 1;
}
