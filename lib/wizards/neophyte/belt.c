inherit "obj/armour";
#include <ansi.h>
start() {
        set_class(1);
        set_name("belt");
        set_slot("belt");
        set_short("A Greenish belt '"+GREEN_F+"I am playing questmud <tm>"+OFF+"'");
        set_long("A green coloured belt with text saying 'iam playing questmud'. Somehow you start to feel shame.");
set_weight(100);
set_value(0);
}

string query_auto_load() { return "/wizards/neophyte/belt.c:"; }