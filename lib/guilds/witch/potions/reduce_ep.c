#include "/guilds/witch/effects.c"
object tp;
int hh;
start(int bonus, object ob) {
tp = ob;
hh = bonus;
tp->reduce_ep(hh);
tell_object(tp, "You feel drained.\n");
return 1;
}

