#include <ansi.h>

inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("banana");
set_id("Banana");
set_alias("monkey_banana");
set_short("A ripe banana <"+BOLD+GREEN_F+"green"+OFF+" glow>");
set_long("A ripe, juicy banana.\n");
set_weight(10);
set_value(1);
set_strength(2100);
}

set_id(arg) {
    return name == arg;
}

