#include "/guilds/witch/effects.c"
object tp;
start(int bonus, object ob) {
tp = ob;
tell_object(tp, "The burning fire scorches your skin!.\n");
tp->hit_with_spell((SINGLE_DAMA)+random(50), "fire");
return 1;
}

