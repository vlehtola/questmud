#include "/guilds/witch/effects.c"
object tp;
int effect;
start(int bonus, object ob) {
tp = ob;
effect = bonus/5;
if(tp->query_enhanced()) { write("Nothing happens.\n"); return 1; }
write("The "+ob->query_name()+" is enchanced.\n");
shadow(tp, 1);
tp->set_stats("con", tp->query_stats("con")+effect);
call_out("end_con_boost", bonus*60);
return 1;
}

end_con_boost() {
        tp->start();
        destruct(this_object());
}

query_enhanced() { return this_object(); }