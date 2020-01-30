#include <ansi.h>
inherit "obj/weapon";
drop() { return 1; }

start()  {
    set_class(9);
    set_sub_type("knuckles {*BLACK*}");
set_name("knuckles");
set_short("Shining mithril combat knuckles {"+CYAN_F+"*BLACK*"+OFF+"}");
set_alias("knuckles");
    set_long("Shining combat knuckles made of the finest mithril in the world.\n"
     "Every martial artists have their own knuckles which presents their\n"
     "rank and how advanced they are. These knuckles are the most powerful\n"
     "ones and only a Grand Master can use them properly.");
}

query_no_save()  { return 1;}
