#include "/guilds/witch/effects.c"
object tp;
int hh;
start(int bonus, object ob) {
tp = ob;
hh = REGEN_TIME;
if(tp->query_epr_boost()) {
        tell_object(tp, "Nothing happens.\n");
        destruct(this_object());
        return 1;
}
tell_object(tp, "Your endurance point regeneration is going faster.\n");
shadow(tp, 1);
call_out("end_epr_boost", bonus*2);
return 1;
}

query_epr_boost() { return this_object(); }

shadow_heart_beat() {
  tp->add_ep(hh);
}
end_epr_boost() {
        tell_object(tp, "Your endurance point regeneration is lowered to the natural state.\n");
        destruct(this_object());
        return 1;
}

