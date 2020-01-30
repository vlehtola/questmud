#include "/guilds/witch/effects.c"
object tp;
int effect;
start(int bonus, object ob) {
tp = ob;
effect = bonus/5;
if(tp->query_enhanced()) { write("Nothing happens.\n"); return 1; }
write("The "+ob->query_name()+" is enchanced.\n");
shadow(tp, 1);
tp->set_stats("int", tp->query_stats("int")+effect);
call_out("end_int_boost", bonus*60);
return 1;
}

end_int_boost() {
        tp->start();
        destruct(this_object());
}

query_enhanced() { return this_object(); }
