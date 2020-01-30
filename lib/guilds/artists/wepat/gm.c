#include <ansi.h>
inherit "obj/weapon";
start()  {
    set_class(9);
    set_sub_type("knuckles {*BLACK*}");
set_name("knuckles");
set_short("Shining mithril combat knuckles {"+CYAN_F+"*BLACK*"+OFF+"}");
set_alias("nyrkkirauta");
    set_long("Shining combat knuckles made of the finest mithril in the world.\n"
     "Every martial artists have their own knuckles which presents their\n"
     "rank and how advanced they are. These knuckles are the most powerful\n"
     "ones and only a Grand Master can use them properly.\n"
     "You can destroy your knuckles with command: dest knuckles\n");
}

init() {
    ::init();
   add_action("dest", "dest");
   add_action("quit", "quit");
}
int dest(string str) {
if ( str == "knuckles" ) {
write("You destroy your knuckles\n");
destruct(this_object());
return 1;
}
}
int quit() {
write("You cannot quit while holding knuckles. Destruct them first\n");

return 1;
}

query_no_save() { return 1; }
drop() { return 1; }
