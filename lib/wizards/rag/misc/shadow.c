#include <ansi.h>

object liv;

start(object mina) {
   if (!mina) { return; }
   liv = mina;
   shadow(liv,1);
}

query_plan() {
string plan;

if ( this_player()->query_terminal() ) {
        plan = BOLD+CYAN_F+"http://www.lanttu.tk"+OFF+"\n\n";
} else {
        plan ="http://www.lanttu.tk\n\n";
}

plan += "Bughunter / Wizard helper\n";
plan += "I'm currently busy at school and other projects\n";
plan += "but I try to log in every now and then.\n";

plan += "\nRemember to behave, ";
plan += this_player()->query_name();
plan += "!\nArchwizards never sleep...\n";

return plan;
}


query_rag_shadow() {
        return 1;
}

end_rag_shadow() {
        destruct(this_object());
}
