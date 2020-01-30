#include <ansi.h>
inherit "obj/weapon";
drop() { return 1; }
start()  {
    set_class(4);
    set_sub_type("knuckles {Yellow}");
set_name("knuckles");
set_short("Shining mithril combat knuckles {"+YELLOW_F+"Yellow"+OFF+"}");
set_alias("nyrkkirauta");
    set_long("Shining combat knuckles made of the finest mithril in the world.\n"
     "Every martial artists have their own knuckles which presents their\n"
     "rank and how advanced they are in martial arts.\n"+
     "You can destroy your knuckles with command: dest knuckles\n");
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
query_no_save() { return 1; }
