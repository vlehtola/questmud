#include "/guilds/witch/effects.c"
object tp;
int hh;
start(int dama, object ob) {
tp = ob;
hh = dama;
tell_object(tp, "Your head starts to hurt!\n");
tp->set_stunned(random(3)+1);
return 1;
}

