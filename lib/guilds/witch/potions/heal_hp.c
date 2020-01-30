#include "/guilds/witch/effects.c"
object tp;
int hh;
start(int bonus, object ob) {
tp = ob;
hh = HEAL_CALC;
tp->add_hp(hh);
tell_object(tp, "You feel healed.\n");
return 1;
}

