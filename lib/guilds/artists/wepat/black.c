#include <ansi.h>
inherit "obj/weapon";

start()  {
    set_class(8);
    set_sub_type("knuckles {Black}");
set_name("knuckles");
set_short("Shining mithril combat knuckles {"+CYAN_F+"Black"+OFF+"}");
set_alias("nyrkkirauta");
    set_long("Shining combat knuckles made of the finest mithril in the world.\n"+
     "Every martial artists have their own knuckles which presents their\n"+
     "rank and how advanced they are in martial arts.\n"+
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
write("You cannot quit while wielding your knuckles. Destruct them first\n");
return 1;
}


drop() { return 1; }
query_no_save() { return 1; }
