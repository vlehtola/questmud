#include "/guilds/witch/effects.c"
object tp;
start(int bonus, object ob) {
tp = ob;
tell_object(tp, "The freezing pain really HURTS!.\n");
tp->hit_with_spell((SINGLE_DAMA)+random(50), "cold");
return 1;
}

