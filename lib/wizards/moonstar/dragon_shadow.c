object liv;
#include <ansi.h>
start(object mina) {
   if (!mina) { return; }
   liv = mina;
   shadow(liv,1);
   tell_object(liv, "You feel dragonic!\n");
   mina->update_stats();
}

end_dragon_shadow() {
destruct(this_object());
}

short() {
        return ""+RED_F+"Moonstar the friendly dictator"+OFF+"";
}

query_str() {
        return liv->query_str()+300;
}

query_con() {
        return liv->query_con()+300;
}

query_size() {
        return 100;
}

query_dex() {
        return liv->query_dex()+150;
}
