#include "/guilds/witch/effects.c"
object tp;
int bonus;
start(int bon, object ob) {
tp = ob;
bonus = bon;
if(tp->query_curse()) {
        tell_object(tp, "Nothing happens.\n");
        destruct(this_object());
        return 1;
        }
shadow(tp,1);
update_stats();
tell_object(tp, "You feel cursed.\n");
call_out("end_str_curse", (bon*2)+random(180));
return 1;
}

query_curse() { return this_object(); }

end_str_curse() {
        tell_object(tp, "You feel your curse leaving from your body.\n");
        destruct(this_object());
        return 1;
}

update_stats() {
        tp->update_stats();
        tp->set_str(tp->query_str()/2);
}
