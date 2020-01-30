#include "/guilds/witch/effects.c"
object tp;
int hh;
start(int bonus, object ob) {
tp = ob;
hh = REGEN_TIME;
if(tp->query_hpr_boost()) {
        tell_object(tp, "Nothing happens.\n");
        destruct(this_object());
        return 1;
}
tell_object(tp, "Your hit point regeneration is going faster.\n");
shadow(tp, 1);
call_out("end_hpr_boost", bonus*2);
return 1;
}

query_hpr_boost() { return this_object(); }

end_hpr_boost() {
        tell_object(tp, "Your hit point regeneration is lowered to the natural state.\n");
        destruct(this_object());
        return 1;
}

shadow_heart_beat() {
  tp->add_hp(hh);
}
