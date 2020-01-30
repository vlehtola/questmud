#include <ansi.h>
inherit "obj/weapon";

start()  {
    set_class(8);
    set_sub_type("knuckles {Black}");
set_name("knuckles");
set_short("Shining mithril combat knuckles {"+CYAN_F+"Black"+OFF+"}");
set_alias("knuckles");
    set_long("Shining combat knuckles made of the finest mithril in the world.\n"
     "Every martial artists have their own knuckles which presents their\n"
     "rank and how advanced they are in martial arts.\n");
}
init() {
    ::init();
   add_action("dest", "dest");
}
int dest(string str) {
if ( str == "knuckles" ) {
write("You destroy your knuckles\n");
destruct(this_object());
return 1;
}
}

