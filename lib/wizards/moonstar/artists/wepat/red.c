#include <ansi.h>
inherit "obj/weapon";
drop()  { return 1; }

start()  {
    set_class(7);
    set_sub_type("knuckles {Red}");
set_name("knuckles");
set_short("Shining mithril combat knuckles {"+sprintf("%c",27)+"[1;1;31m"+"Red"+OFF+"}");
set_alias("knuckles");
    set_long("Shining combat knuckles made of the finest mithril in the world.\n"
     "Every martial artists have their own knuckles which presents their\n"
     "rank and how advanced they are in martial arts.\n");
}

query_no_save() { return 1;  }
