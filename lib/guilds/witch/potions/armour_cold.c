#include "/guilds/witch/effects.c"
object tp;
int effect;
start(int bonus, object ob) {
tp = ob;
effect = bonus/2;
if(tp->query_resist_enhanced()) { write("Nothing happens.\n"); return 1; }
write("The "+ob->query_name()+" is enchanced.\n");
shadow(tp, 1);
tp->set_stats("cold", tp->query_stats("cold")+effect);
call_out("end_cold_boost", bonus*60);
return 1;
}

end_cold_boost() {
        tp->start();
        destruct(this_object());
}

query_resist_enhanced() { return this_object(); }
