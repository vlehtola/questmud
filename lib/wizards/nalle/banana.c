#include <ansi.h>

inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("banana");
set_short("A ripe banana <"+BOLD+GREEN_F+"green"+OFF+" glow>");
set_long("A big, long, juicy, thick, mature, ripe, warm, hard, bent banana.\n");
set_weight(1);
set_value(1);
set_strength(2100000);
}

/*
set_id(arg) {
    return name == arg;
}
 */
