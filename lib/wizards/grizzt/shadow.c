#include <ansi.h>

object liv;

start(object mina) {
   if (!mina) { return; }
   liv = mina;
   shadow(liv,1);
   tell_object(liv, "Entering the shadows...\n");
}
self_destruct() {
destruct(this_object());
}

query_plan() {
int i;
string plan;
i = this_player()->query_terminal();
if(i) { plan = BOLD+CYAN_F+"http://lanttu.cjb.net"+OFF+"\n";
} else { plan ="http://lanttu.cjb.net\n"; }

plan += "\nNext projects: The legendary treasure hunt event\n";
plan +=   "               Fixing all kinds of things :)\n";
plan +=   "               New guild with Jenny\n";
plan +=   "               Castles???\n";
plan +=   "\nRemember to behave, ";
plan +=   this_player()->query_name();
plan +=   "!\nArchwizards never sleep...\n";

return plan;
}
