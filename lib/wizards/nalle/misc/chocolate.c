#include <ansi.h>

inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("chocolate");
set_alias("bar");
set_short("A tasty chocolate bar <"+BOLD+YELLOW_F+"yellow"+OFF+" glow>");
set_long("A tasty looking bar of chocolate, made by some Duranghomian alchemist.\n");
set_weight(10);
set_value(1);
set_strength(100000);
}

set_id(arg) {
    return name == arg;
}

