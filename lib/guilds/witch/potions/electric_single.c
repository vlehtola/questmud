#include "/guilds/witch/effects.c"

object tp;
start(int bonus, object ob) {
tp = ob;
tell_object(tp, "The blood inside you starts to boil and that HURTS!.\n");
tp->hit_with_spell((SINGLE_DAMA)+random(50), "electric");
return 1;
}

